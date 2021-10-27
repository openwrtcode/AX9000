#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD= CAPTUREFFTREPORTS 

# cmd parm
PARM_START:
UINT32:fftreportsize:1:u:0
UINT32:offset:1:u:0
UINT32:size:1:u:0
UINT8:phyId:1:u:0
PARM_END:

# rsp
RSP= CAPTUREFFTREPORTSRSP

# rsp parm
PARM_START:
UINT32:fftStatus:1:u:0
UINT32:offset:1:u:0
UINT32:size:1:u:0
DATA4096:data4k:4096:x
PARM_END:
