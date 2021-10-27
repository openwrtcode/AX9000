#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD=TpcFullPtSetPreCalData        

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:overrideEnable:1:u:0
UINT8:band:1:u:0
UINT8:pad1:1:u:0
UINT16:TpcFreqFullPt:32:u:
UINT8:TpcCalDataTgtPwr:32:u:
UINT8:TpcCalRfGain:32:u:
PARM_END:

# rsp
RSP= TpcFullPtSetPreCalDataRsp

# rsp parm
PARM_START:
UINT8:status:1:u:0
PARM_END:

