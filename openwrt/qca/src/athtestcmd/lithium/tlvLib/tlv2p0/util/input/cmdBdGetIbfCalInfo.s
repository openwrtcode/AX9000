#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD= BdGetIbfCalInfo

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
PARM_END:

# rsp
RSP= BdGetIbfCalInfoRsp

# rsp parm
PARM_START:
UINT8:status:1:u:0
UINT8:numFreq:1:u:3
UINT8:numChain:1:u:2
UINT8:pad1:1:x:0
UINT32:freqOffset:1:u:0
UINT32:ibfCalDataOffset:1:u:0
PARM_END: