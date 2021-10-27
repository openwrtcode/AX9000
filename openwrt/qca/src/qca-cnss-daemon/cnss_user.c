/*
 * Copyright (c) 2019-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "debug.h"
#include "wlfw_qmi_client.h"
#include "cnss_cli.h"
#include "cnss_genl.h"
#include "cnss_genl_msg.h"

static int cnss_user_sock;

int cnss_user_get_fd(void)
{
	if (cnss_user_sock > 0)
		return cnss_user_sock;
	else
		return -1;
}

int cnss_user_socket_init(void)
{
	int sockfd;
	struct sockaddr_in address;
	int ret = 0;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		wsvc_printf_err("Fail to create user socket %d\n", sockfd);
		return sockfd;
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	ret = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
	if (ret < 0) {
		wsvc_printf_err("Fail to bind user socket %d\n", ret);
		close(sockfd);
		return ret;
	}

	cnss_user_sock = sockfd;
	return 0;
}

static void handle_qdss_trace_start(void)
{
	wlfw_qdss_trace_start(0);
}

static
void handle_qdss_trace_stop(struct cnss_cli_qdss_trace_stop_data *data)
{
	wlfw_qdss_trace_stop(data->option, data->instance_id);
}

static void handle_qdss_trace_config_download(void)
{
	wlfw_send_qdss_trace_config_download_req(0);
}

static void handle_qdss_trace_config_and_start(
		struct cnss_cli_qdss_trace_load_and_start_data *data)
{
	wlfw_qdss_trace_config_download_and_start(data->instance_id);
}

static void handle_config_param(enum cnss_cli_cmd_type type,
				struct cnss_cli_config_param_data *data)
{
	switch (type) {
	case QDSS_TRACE_DATA_FILE_SIZE:
		/* value is in MB, convert it to bytes */
		wlfw_set_qdss_max_file_len(data->instance_id,
					   data->value*1024*1024);
		break;
	case DAEMON_SUPPORT:
		cnss_genl_send_data(CNSS_GENL_MSG_TYPE_DAEMON_SUPPORT,
				    data->instance_id, data->value);
		break;
	case COLD_BOOT_SUPPORT:
		cnss_genl_send_data(CNSS_GENL_MSG_TYPE_COLD_BOOT_SUPPORT,
				    data->instance_id, data->value);
		break;
	default:
		wsvc_printf_err("Unknown config param type %d\n", type);
	}
}

void handle_cnss_user_event(int fd)
{
	unsigned int rbytes = 0;
	char *buffer = NULL;
	struct cnss_cli_msg_hdr *hdr = NULL;
	struct sockaddr_in remote_addr;
	unsigned int addrlen = sizeof(remote_addr);
	void *data = NULL;

	buffer = malloc(CNSS_CLI_MAX_PAYLOAD);
	if (!buffer) {
		wsvc_printf_err("Failed to allocate memory for user event buffer");
		return;
	}

	rbytes = recvfrom(fd, buffer, CNSS_CLI_MAX_PAYLOAD, 0,
			  (struct sockaddr *)&remote_addr, &addrlen);
	if (rbytes <= 0)
		goto out;

	hdr = (struct cnss_cli_msg_hdr *)buffer;
	wsvc_printf_err("Receive user message: %d, len %d\n",
			hdr->type, hdr->len);
	switch (hdr->type) {
	case QDSS_TRACE_START:
		handle_qdss_trace_start();
		break;
	case QDSS_TRACE_STOP:
		if (hdr->len != sizeof(struct cnss_cli_qdss_trace_stop_data)) {
			wsvc_printf_err("Invalid data length: %d\n", hdr->len);
			goto out;
		}
		data = (char *)hdr + sizeof(struct cnss_cli_msg_hdr);
		handle_qdss_trace_stop(
				(struct cnss_cli_qdss_trace_stop_data *)data);
		break;
	case QDSS_TRACE_CONFIG_DOWNLOAD:
		handle_qdss_trace_config_download();
		break;
	case QDSS_TRACE_CONFIG_AND_START:
		if (hdr->len !=
		    sizeof(struct cnss_cli_qdss_trace_load_and_start_data)) {
			wsvc_printf_err("Invalid data length: %d\n", hdr->len);
			goto out;
		}
		data = (char *)hdr + sizeof(struct cnss_cli_msg_hdr);
		handle_qdss_trace_config_and_start(
			(struct cnss_cli_qdss_trace_load_and_start_data *)data);
		break;
	case QDSS_TRACE_DATA_FILE_SIZE:
	case DAEMON_SUPPORT:
	case COLD_BOOT_SUPPORT:
		if (hdr->len != sizeof(struct cnss_cli_config_param_data)) {
			wsvc_printf_err("Invalid data length %d for type %d\n",
					hdr->len, hdr->type);
			goto out;
		}
		data = (char *)hdr + sizeof(struct cnss_cli_msg_hdr);
		handle_config_param(hdr->type,
				    (struct cnss_cli_config_param_data *)data);
		break;
	default:
		wsvc_printf_err("Unknown command %d\n", hdr->type);
		break;
	}
out:
	free(buffer);
}
