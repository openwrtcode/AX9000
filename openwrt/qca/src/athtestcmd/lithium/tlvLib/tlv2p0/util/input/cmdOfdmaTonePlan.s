#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================

#define TLV2_OFDMA_TONE_PLAN_SIZE    1054


# cmd
CMD= ofdmaTonePlan

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:ofdmaTonePlan:TLV2_OFDMA_TONE_PLAN_SIZE:1054:u
PARM_END:

# rsp
RSP= ofdmaTonePlanRsp

# rsp parm
PARM_START:
UINT8:status:1:u:0
UINT8:numRuSupported:1:u:0
PARM_END:
