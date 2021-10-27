#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD=TpcSetCalChainMasks      

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:pad1:1:u:0
UINT16:txMask2G:1:u:0
UINT16:rxMask2G:1:u:0
UINT16:txMask5G:1:u:0
UINT16:rxMask5G:1:u:0
UINT32:concurrencyModeMask:1:u:0
PARM_END:

# rsp
RSP= TpcSetCalChainMasksRsp

# rsp parm
PARM_START:
UINT8:status:1:u:0
PARM_END:

