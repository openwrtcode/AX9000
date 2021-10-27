#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD= CONFIGURESPECTRALSCAN 

# cmd parm
PARM_START:
UINT16:freq:1:u:0
UINT16:freq2:1:u:0
UINT16:chainMask:1:u
UINT8:bandwidth:1:u:0
UINT8:ScanCount:1:u:0
UINT8:ScanPeriod:1:u:0
UINT8:ScanPriority:1:u:0
UINT8:ScanFFTSize:1:u:0
UINT8:ScanGCEna:1:u:0
UINT8:ScanRestartEna:1:u:0
UINT8:ScanInitDelay:1:u:0
UINT8:ScanNBToneThr:1:u:0
UINT8:ScanStrBinThr:1:u:0
UINT8:ScanWBRptMode:1:u:0
UINT8:ScanRssiRptMode:1:u:0
UINT8:ScanPwrFormat:1:u:0
UINT8:ScanRptMode:1:u:0
UINT8:ScanBinScale:1:u:0
UINT8:ScandBmAdj:1:u:0
UINT8:ScanChnMask:1:u:0
UINT8:phyId:1:u:0
INT32:ScanRssiThr:1:d:0
INT32:ScanNoiseFloorRef:1:d:0
PARM_END:

# rsp
RSP= CONFIGURESPECTRALSCANRSP

# rsp parm
PARM_START:
UINT32:fftreportsize:1:u:0
PARM_END:
