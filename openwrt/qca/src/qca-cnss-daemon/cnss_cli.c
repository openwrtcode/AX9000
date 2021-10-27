/*
 * Copyright (c) 2019-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <getopt.h>
#include "cnss_cli.h"
#include "wlfw_qmi_client.h"

#define MAX_CMD_LEN 256
#define MAX_NUM_OF_PARAMS 2
#define MAX_CNSS_CMD_LEN 32

/* Below QDSS File sizes are in MB */
#define MIN_QDSS_FILE_SIZE 1
#define MAX_QDSS_FILE_SIZE 8

#define ARRAY_SIZE(x)   (sizeof(x)/sizeof(x[0]))

static void usage(char *progname)
{
	fprintf(stderr, "usage: %s [options] \n"
		"   -i along with any other option is mandatory for usage\n"
		"   Sample usage: cnsscli -i pci0 --qdss_start, cnsscli -i pci0 --qdss_stop 0x3f\n\n"
		"   -i, --interface            Interface selected, like integrated pci0 pci1 integrated1 integrated2\n"
		"   --qdss_start               Do qdss_trace_load_config followed by qdss_trace_start \n"
		"   --qdss_stop                Do qdss_trace_stop with option number\n"
		"   --qdss_file_size           Set QDSS trace data file size between 1MB to 8MB \n"
		"   --enable_daemon_support    Enable daemon support in kernel for given interface\n"
		"   --enable_cold_boot_support Enable cold boot support in kernel for given interface\n"
		"   -h, --help                 Display this help text\n",
		progname);
	exit(EXIT_FAILURE);
}

static char *cnss_cmd[][2] = {
	{"qdss_trace_start", ""},
	{"qdss_trace_stop", "<Hex base number: e.g. 0x3f>"},
	{"qdss_trace_load_config", ""},
	{"quit", ""}
};

void help(void)
{
	int i = 0;

	printf("Supported Command:\n");
	for (i = 0; i < (int)ARRAY_SIZE(cnss_cmd); i++)
		printf("%s %s\n", cnss_cmd[i][0], cnss_cmd[i][1]);
}

static void handle_non_interactive_cmd(char *buffer, int sockfd,
				       int argc, char **argv)
{
	int c;
	enum cnss_cli_cmd_type type = CNSS_CLI_CMD_NONE;
	struct cnss_cli_msg_hdr *hdr = NULL;
	void *cnss_cli_data = NULL;
	struct sockaddr_in serv_addr;
	struct cnss_cli_qdss_trace_load_and_start_data load_start_data;
	struct cnss_cli_qdss_trace_stop_data stop_data;
	struct cnss_cli_config_param_data config_param;
	uint32_t stop_option = 0;
	uint32_t instance_id = 0;
	uint32_t value = 0;
	char *interface_name = NULL;
	char *progname = NULL;
	static struct option options[] = {
		{"help", no_argument, NULL, 'h'},
		{"interface", required_argument, NULL, 'i'},
		{"qdss_start", no_argument, NULL, 's'},
		{"qdss_stop", required_argument, NULL, 'x'},
		{"qdss_file_size", required_argument, NULL, 'z'},
		{"enable_daemon_support", required_argument, NULL, 'd'},
		{"enable_cold_boot_support", required_argument, NULL, 'c'},
		{0, 0, 0, 0}
	};

	progname = argv[0];

	while (1) {
		c = getopt_long(argc, argv, "hi:sx:d:c:z:", options, NULL);

		if (c < 0)
			break;

		switch (c) {
		case 'i':
			interface_name = optarg;
			break;
		case 's':
			type = QDSS_TRACE_CONFIG_AND_START;
			break;
		case 'x':
			stop_option = strtoull(optarg, NULL, 0);
			type = QDSS_TRACE_STOP;
			break;
		case 'z':
			type = QDSS_TRACE_DATA_FILE_SIZE;
			value = strtol(optarg, NULL, 0);
			break;
		case 'd':
			type = DAEMON_SUPPORT;
			value = strtol(optarg, NULL, 0);
			break;
		case 'c':
			type = COLD_BOOT_SUPPORT;
			value = strtol(optarg, NULL, 0);
			break;
		case 'h':
		default:
			usage(progname);
			break;
		}
		if ((type != CNSS_CLI_CMD_NONE) && interface_name)
			break;
	}
	if (optind < argc) {
		usage(progname);
		return;
	}

	if (!interface_name) {
		printf("\nMandatory interface option missing!!!");
		return;
	}

	if (!strncmp(interface_name, "integrated1", 11))
		instance_id = SPRUCE_1_ID;
	else if (!strncmp(interface_name, "integrated2", 11))
		instance_id = SPRUCE_2_ID;
	else if (!strncmp(interface_name, "integrated", 10))
		instance_id = HAWKEYE_ID;
	else if (!strncmp(interface_name, "pci0", 4))
		instance_id = PINE_1_ID;
	else if (!strncmp(interface_name, "pci1", 4))
		instance_id = PINE_2_ID;

	if (!instance_id) {
		printf("\nInvalid interface name %s", interface_name);
		return;
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	inet_pton(AF_INET, NAME, &serv_addr.sin_addr);

	hdr = (struct cnss_cli_msg_hdr *)buffer;
	hdr->type = type;

	switch (type) {
	case QDSS_TRACE_CONFIG_AND_START:
		hdr->len = sizeof(load_start_data);
		load_start_data.instance_id = instance_id;
		cnss_cli_data = (char *)hdr + sizeof(struct cnss_cli_msg_hdr);
		memcpy(cnss_cli_data, &load_start_data,
		       sizeof(load_start_data));
		break;
	case QDSS_TRACE_STOP:
		hdr->len = sizeof(stop_data);
		stop_data.instance_id = instance_id;
		stop_data.option = stop_option;
		cnss_cli_data = (char *)hdr + sizeof(struct cnss_cli_msg_hdr);
		memcpy(cnss_cli_data, &stop_data, sizeof(stop_data));
		break;
	case QDSS_TRACE_DATA_FILE_SIZE:
		if (value < MIN_QDSS_FILE_SIZE || value > MAX_QDSS_FILE_SIZE) {
			printf("\nInvalid value %d, Supported values <1-8>\n",
			       value);
			return;
		}
		/* If value in valid range, fall-thru */
	case DAEMON_SUPPORT:
	case COLD_BOOT_SUPPORT:
		hdr->len = sizeof(config_param);
		config_param.instance_id = instance_id;
		config_param.value = value;
		cnss_cli_data = (char *)hdr + sizeof(struct cnss_cli_msg_hdr);
		memcpy(cnss_cli_data, &config_param,
		       sizeof(config_param));
		break;
	default:
		usage(progname);
		return;
	}

	sendto(sockfd, buffer, CNSS_CLI_MAX_PAYLOAD, 0,
	       (struct sockaddr *)&serv_addr, sizeof(serv_addr));
}

int main(int argc, char **argv)
{
	char *tmp = NULL;
	char cmd_str[MAX_CMD_LEN];
	char token[MAX_NUM_OF_PARAMS][MAX_CNSS_CMD_LEN];
	int token_num = 0;
	int i = 0;
	int sockfd = 0;
	char *buffer = NULL;
	struct cnss_cli_msg_hdr *hdr = NULL;
	void *cnss_cli_data = NULL;
	enum cnss_cli_cmd_type type = CNSS_CLI_CMD_NONE;
	struct sockaddr_in serv_addr;
	struct cnss_cli_qdss_trace_stop_data stop_data;
	char *pend;

	buffer = malloc(CNSS_CLI_MAX_PAYLOAD);
	if (!buffer) {
		printf("Failed to allocate buffer\n");
		return -1;
	}
	memset(buffer, 0, CNSS_CLI_MAX_PAYLOAD);

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		printf("Failed to connect to cnss-daemon\n");
		free(buffer);
		return -1;
	}

	if (argc > 1) {
		handle_non_interactive_cmd(buffer, sockfd, argc, argv);
		goto out;
	}

	while (1) {
		printf("cnss_cli_cmd >> ");
		fgets(cmd_str, MAX_CMD_LEN, stdin);
		if (!strcmp(cmd_str, "\n"))
			continue;

		tmp = &cmd_str[0];
		i = 0;
		int len = 0;
		char *tmp1;

		while (*tmp != '\0') {
			if (i >= MAX_NUM_OF_PARAMS) {
				printf("Invalid input, max number of params is %d\n",
				       MAX_NUM_OF_PARAMS);
				break;
			}
			tmp1 = tmp;
			len = 0;

			while (*tmp1 == ' ') {
				tmp1++;
				tmp++;
			}
			while (*tmp1 != ' ' && *tmp1 != '\n') {
				len++;
				tmp1++;
			}
			if (*tmp1 != '\n')
				*tmp1 = '\0';

			strlcpy(token[i], tmp, sizeof(token[i]));
			token[i][len] = '\0';
			tmp = tmp1;
			if (*tmp == '\n')
				break;
			tmp++;
			i++;
		}

		if (i >= MAX_NUM_OF_PARAMS)
			continue;

		token_num = i + 1;

		if (!strcmp(token[0], "qdss_trace_start")) {
			type = QDSS_TRACE_START;
		} else if (!strcmp(token[0], "qdss_trace_stop")) {
			if (token_num != 2) {
				printf("qdss_trace_stop <option>\n");
				continue;
			}
			type = QDSS_TRACE_STOP;
		} else if (!strcmp(token[0], "qdss_trace_load_config")) {
			type = QDSS_TRACE_CONFIG_DOWNLOAD;
		} else if (!strcmp(token[0], "help")) {
			help();
			type = CNSS_CLI_CMD_NONE;
		} else if (!strcmp(token[0], "quit")) {
			goto out;
		} else {
			printf("Invalid command %s\n", token[0]);
			type = CNSS_CLI_CMD_NONE;
		}

		if (type == CNSS_CLI_CMD_NONE)
			continue;

		memset(&serv_addr, 0, sizeof(serv_addr));
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(PORT);
		inet_pton(AF_INET, NAME, &serv_addr.sin_addr);

		hdr = (struct cnss_cli_msg_hdr *)buffer;
		hdr->type = type;

		switch (type) {
		case QDSS_TRACE_START:
		case QDSS_TRACE_CONFIG_DOWNLOAD:
			hdr->len = 0;
			break;
		case QDSS_TRACE_STOP:
			hdr->len = sizeof(stop_data);
			stop_data.instance_id = 0;
			stop_data.option = strtoull(token[1], &pend, 16);
			cnss_cli_data = (char *)hdr +
					sizeof(struct cnss_cli_msg_hdr);
			memcpy(cnss_cli_data, &stop_data, sizeof(stop_data));
			break;
		default:
			goto out;
		}

		sendto(sockfd, buffer, CNSS_CLI_MAX_PAYLOAD, 0,
		       (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	}
out:
	free(buffer);
	close(sockfd);
	return 0;
}
