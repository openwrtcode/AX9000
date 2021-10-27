/*
 * Copyright (c) 2019-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */


#ifndef __CNSS_CLI_H__
#define __CNSS_CLI_H__

#define NAME "127.0.0.1"
#define PORT 8080
#define CNSS_CLI_MAX_PAYLOAD 1024

enum cnss_cli_cmd_type {
	CNSS_CLI_CMD_NONE = 0,
	QDSS_TRACE_START,
	QDSS_TRACE_STOP,
	QDSS_TRACE_CONFIG_DOWNLOAD,
	QDSS_TRACE_CONFIG_AND_START,
	QDSS_TRACE_DATA_FILE_SIZE,
	DAEMON_SUPPORT,
	COLD_BOOT_SUPPORT
};

struct cnss_cli_msg_hdr {
	enum cnss_cli_cmd_type type;
	int len;
};

struct cnss_cli_qdss_trace_load_and_start_data {
	unsigned int instance_id;
};

struct cnss_cli_qdss_trace_stop_data {
	unsigned int instance_id;
	unsigned long long option;
};

struct cnss_cli_config_param_data {
	unsigned int instance_id;
	unsigned int value;
};
#endif

