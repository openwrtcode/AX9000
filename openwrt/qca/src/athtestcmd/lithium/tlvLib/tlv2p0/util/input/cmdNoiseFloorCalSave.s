#===============================================================================
# Copyright (c) 2017-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================

#ifndef TLV2_MAX_CHAIN
#define TLV2_MAX_CHAIN          16
#endif
#define FTM_NF_CAL_FREQ_NUM     16
#define FTM_NF_CAL_VALUE_NUM    (FTM_NF_CAL_FREQ_NUM * TLV2_MAX_CHAIN)


CMD= NOISEFLOORCALSAVE

# cmd parm
PARM_START:
UINT16:freqs:FTM_NF_CAL_FREQ_NUM:16:u
UINT32:NFCalValues:FTM_NF_CAL_VALUE_NUM:256:d
UINT16:itemNum:1:u:0
UINT8:phyId:1:u:0
PARM_END:

# rsp

RSP= NOISEFLOORCALSAVERsp
# rsp parm
PARM_START:
UINT32:status:1:u:0
UINT8:phyId:1:u:0
PARM_END:
