#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD= CoexReq

# cmd parm
PARM_START:
UINT32:WlanCoexWeight:11:u
UINT16:shareChainMask:1:u:1
UINT8:enableDynamicAggr:1:u:0
UINT8:enableConcurrentTxChain0:1:u:0
UINT8:btRxAllowWlanTxUnshared:1:u:0
UINT8:btTxAllowWlanTxShared:1:u:0
UINT8:wlanTxAllowBtRxShared:1:u:0
UINT8:wlanRxAllowBtTxShared:1:u:0
UINT8:concurrentTxEnable:1:u:0
UINT8:btRxAllowWlanUnsharedTx:1:u:0
UINT8:wlan1sRxBtTx:1:u:0
UINT8:enableBtContInfo:1:u:0
UINT8:enableBtSchedInfo:1:u:0
UINT8:enableBtLnaInfo:1:u:0
PARM_END:

# rsp
RSP= CoexReqRsp

# rsp parm
PARM_START:
UINT8:status:1:u:0
UINT8:reason:1:u:0
PARM_END:

