
/*
* Copyright (c) 2017,2020 Qualcomm Technologies, Inc.
*
* All Rights Reserved.
* Confidential and Proprietary - Qualcomm Technologies, Inc.
*
*/

#ifndef _OSIF_H_
#define _OSIF_H_

#ifdef USE_NETLINK

#include "libtcmd.h"
#define UTF_CMD_INIT(ifname, rx_cb) tcmd_tx_init(ifname, rx_cb);
#define UTF_CMD_SEND(buf, len, responseNeeded) {\
            tcmd_tx_start();\
            tcmd_tx(buf, len, responseNeeded);\
            }
#define UTF_RFSIM_INIT(ip_port)
#define NETLINK_STREAM_SHIFT       0
#define STREAM_SHIFT               NETLINK_STREAM_SHIFT

#else /* USE_NETLINK */

#define IOCTL_STREAM_SHIFT         8
#define STREAM_SHIFT               IOCTL_STREAM_SHIFT
#ifndef UTFSIM
int cmd_init (char *ifname, void (*rx_cb)(void *buf));
int cmd_end();
void cmd_send (void *buf, int len, unsigned char responseNeeded );

#define UTF_CMD_INIT(ifname, rx_cb) cmd_init(ifname, rx_cb);
#define UTF_CMD_SEND(buf, len, responseNeeded) cmd_send(buf, len, responseNeeded)
#define UTF_RFSIM_INIT(ip_port)

#else /* UTFSIM */

int cmd_init_sim(void (*rx_cb)(void *buf));
void cmd_send_sim(void *buf, int len, unsigned char responseNeeded);
int utf_rfsim_init(char* ip_port);

#define UTF_RFSIM_INIT(ip_port) utf_rfsim_init(ip_port)
#define UTF_CMD_INIT(ifname, rx_cb) cmd_init_sim(rx_cb)
#define UTF_CMD_SEND(buf, len, responseNeeded) cmd_send_sim(buf + 8, len, responseNeeded)

#endif /* UTFSIM */

unsigned int cmd_Art2ReadPciConfigSpace (unsigned int offset);
int cmd_Art2WritePciConfigSpace(unsigned int offset, unsigned int data);
#endif /* USE_NETLINK */
#endif /* _OSIF_H_ */
