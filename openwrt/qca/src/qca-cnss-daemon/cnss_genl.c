/*
 * Copyright (c) 2019-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <poll.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>

#include <netlink/genl/genl.h>
#include <netlink/genl/ctrl.h>

#include "debug.h"
#include "cnss_genl.h"
#include "cnss_genl_msg.h"

#define DEFAULT_QDSS_TRACE_FILE "/data/vendor/wifi/qdss_trace.bin"
#define MAX_FILE_PATH 100

static struct nl_sock *nl_sock;
static int nl_family_id;

static int cnss_genl_qdss_process_cmd(unsigned int total_size, char * file_name, unsigned int seg_id,
				      unsigned char end, unsigned int data_len,
				      void *data)
{
	FILE *fp = NULL;
	char filename[MAX_FILE_PATH];

	if (strcmp(file_name, "default") == 0)
		snprintf(filename, sizeof(filename),
			 DEFAULT_QDSS_TRACE_FILE);
	else
		snprintf(filename, sizeof(filename),
			 "/data/vendor/wifi/%s", file_name);

	wsvc_printf_err("Storing QDSS data to file: %s: total_size %u, seg_id %u, end %u, data_len %u, data %p",
			filename, total_size, seg_id, end, data_len, data);

	fp = fopen(filename, "ab");
	if (fp == NULL) {
		wsvc_printf_err("%s: Failed to open file %s", __func__, filename);
		return -1;
	}

	fwrite(data, 1, data_len, fp);
	fclose(fp);

	return 0;
}

static int cnss_genl_recv_msg(struct nl_msg *nl_msg, void *data)
{

	struct nlmsghdr *nlh = nlmsg_hdr(nl_msg);
	struct genlmsghdr *gnlh = nlmsg_data(nlh);
	struct nlattr *attrs[CNSS_GENL_ATTR_MAX + 1];
	int ret = 0;
	unsigned char type = 0;
	char *file_name = NULL;
	unsigned int total_size = 0;
	unsigned int seg_id = 0;
	unsigned char end = 0;
	unsigned int data_len = 0;
	void *msg_buf = NULL;

	if (gnlh->cmd != CNSS_GENL_CMD_MSG)
		return NL_SKIP;

	wsvc_printf_err("Received CNSS_GENL_CMD_MSG");

	ret = genlmsg_parse(nlh, 0, attrs, CNSS_GENL_ATTR_MAX, NULL);
	if (ret < 0) {
		wsvc_printf_err("RX NLMSG: Parse fail %d", ret);
		return 0;
	}

	type = nla_get_u8(attrs[CNSS_GENL_ATTR_MSG_TYPE]);
	file_name = nla_get_string(attrs[CNSS_GENL_ATTR_MSG_FILE_NAME]);
	total_size = nla_get_u32(attrs[CNSS_GENL_ATTR_MSG_TOTAL_SIZE]);
	seg_id = nla_get_u32(attrs[CNSS_GENL_ATTR_MSG_SEG_ID]);
	end = nla_get_u8(attrs[CNSS_GENL_ATTR_MSG_END]);
	data_len = nla_get_u32(attrs[CNSS_GENL_ATTR_MSG_DATA_LEN]);
	msg_buf = nla_data(attrs[CNSS_GENL_ATTR_MSG_DATA]);

	wsvc_printf_err("RX NLMSG: type %u, file_name %s, total_size %u, seg_id %u, end %u, data_len %u",
			type, file_name, total_size, seg_id, end, data_len);

	if (type == CNSS_GENL_MSG_TYPE_QDSS)
		cnss_genl_qdss_process_cmd(total_size, file_name, seg_id, end, data_len, msg_buf);

	return 0;
}

int cnss_genl_recvmsgs(void)
{
	int ret = 0;

	if (!nl_sock)
		return -EINVAL;

	ret = nl_recvmsgs_default(nl_sock);
	if (ret < 0)
		wsvc_printf_err("NL msg recv error %d", ret);

	return ret;
}

int cnss_genl_send_data(uint8_t type, uint32_t instance_id, uint32_t value)
{
	struct nl_msg *nlmsg;
	void *msg_head = NULL;
	int ret = 0;

	if (!nl_sock) {
		wsvc_printf_err("%s: nl sock is invalid \n", __func__);
		return -EINVAL;
	}

	nlmsg = nlmsg_alloc();
	if (NULL == nlmsg) {
		wsvc_printf_err("%s nl msg alloc failed\n", __func__);
		return -ENOMEM;
	}

	msg_head = genlmsg_put(nlmsg, 0, 0,
			       nl_family_id, 0, 0,
			       CNSS_GENL_CMD_MSG, 0);

	if (!msg_head) {
		ret = -ENOMEM;
		goto fail;
	}

	wsvc_printf_dbg("%s: type:%u, instance_id:%d value:%d\n",
			__func__, type, instance_id, value);

	ret = nla_put_u8(nlmsg, CNSS_GENL_ATTR_MSG_TYPE, type);
	if (ret < 0)
		goto fail;
	ret = nla_put_u32(nlmsg, CNSS_GENL_ATTR_MSG_INSTANCE_ID, instance_id);
	if (ret < 0)
		goto fail;
	ret = nla_put_u32(nlmsg, CNSS_GENL_ATTR_MSG_VALUE, value);
	if (ret < 0)
		goto fail;

	ret = nl_send_auto(nl_sock, nlmsg);
	if (ret < 0)
		goto fail;

	return ret;

fail:
	wsvc_printf_err("genl msg send fail: %d\n", ret);
	if (nlmsg)
		nlmsg_free(nlmsg);
	return ret;
}

int cnss_genl_init(void)
{
	struct nl_sock *sock;
	int ret = 0;
	int mcgrp_id;

	sock = nl_socket_alloc();
	if (!sock) {
		wsvc_printf_err("NL socket alloc fail");
		return -EINVAL;
	}

	ret = genl_connect(sock);
	if (ret < 0) {
		wsvc_printf_err("GENL socket connect fail");
		goto free_socket;
	}

	ret = nl_socket_set_buffer_size(sock, CNSS_GENL_BUF_SIZE, 0);
	if (ret < 0)
		wsvc_printf_err("Could not set NL RX buffer size %d",
				ret);

	nl_family_id = genl_ctrl_resolve(sock, CNSS_GENL_FAMILY_NAME);
	if (nl_family_id < 0) {
		ret = nl_family_id;
		wsvc_printf_err("Couldn't resolve family id");
		goto close_socket;
	}

	mcgrp_id = genl_ctrl_resolve_grp(sock, CNSS_GENL_FAMILY_NAME,
					 CNSS_GENL_MCAST_GROUP_NAME);

	wsvc_printf_err("NL group_id %d, nl_family_id %d",
			mcgrp_id, nl_family_id);

	nl_socket_disable_seq_check(sock);
	ret = nl_socket_modify_cb(sock, NL_CB_MSG_IN,
				  NL_CB_CUSTOM, cnss_genl_recv_msg, NULL);
	if (ret < 0) {
		wsvc_printf_err("Couldn't modify NL cb, ret %d", ret);
		goto close_socket;
	}

	ret = nl_socket_add_membership(sock, mcgrp_id);
	if (ret < 0) {
		wsvc_printf_err("Couldn't add membership to group %d, ret %d",
				mcgrp_id, ret);
		goto close_socket;
	}

	nl_sock = sock;

	return ret;

close_socket:
	nl_close(sock);
free_socket:
	nl_socket_free(sock);
	return ret;
}

int cnss_genl_get_fd(void)
{
	if (!nl_sock)
		return -1;
	else
		return nl_socket_get_fd(nl_sock);
}

void cnss_genl_exit(void)
{
	if (nl_sock) {
		nl_close(nl_sock);
		nl_socket_free(nl_sock);
		nl_sock = NULL;
	}
}
