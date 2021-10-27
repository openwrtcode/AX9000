#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD=Tpc1PtSetChanPwr        

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:chainIdx:1:u:0
UINT8:overrideEnable:1:u:0
UINT8:pad1:1:u:0
UINT16:TpcFreq:8:u:
INT16:TpcPwr:8:u:
PARM_END:

# rsp
RSP= Tpc1PtSetChanPwrRsp

# rsp parm
PARM_START:
UINT8:status:1:u:0
PARM_END:

