#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD= OfdmaUlTxConfig

# cmd parm
PARM_START:
PARM_END:

# rsp
RSP= OfdmaUlTxConfigRsp

# rsp parm
PARM_START:
UINT8:preFECPad:1:u:1
UINT8:ldpcExtraSymbol:1:u:0
UINT8:peDisambiguity:1:u:0
UINT8:packetExt:1:u:0
UINT32:numOfHeLtf:1:u:0
PARM_END:

