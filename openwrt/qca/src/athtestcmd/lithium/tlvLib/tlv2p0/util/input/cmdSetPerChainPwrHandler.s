#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================

# cmd
CMD= SetPerChainPwr

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:pad1:1:u:0
UINT16:chainMask:1:x:0x3
INT8:powerValPerChain:8:x
PARM_END:

# rsp
RSP= SetPerChainPwrRsp

# rsp parm
PARM_START:
UINT8:status:1:u:0
PARM_END:
