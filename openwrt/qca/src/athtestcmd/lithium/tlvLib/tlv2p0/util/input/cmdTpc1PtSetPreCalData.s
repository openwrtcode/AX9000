#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD=Tpc1PtSetPreCalData       

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:calOffsetPower:1:u:0
UINT8:overrideEnable:1:u:0
UINT8:band:1:u:0
UINT16:TpcFreq:8:u:
PARM_END:

# rsp
RSP= Tpc1PtSetPreCalDataRsp

# rsp parm
PARM_START:
UINT8:status:1:u:0
PARM_END:

