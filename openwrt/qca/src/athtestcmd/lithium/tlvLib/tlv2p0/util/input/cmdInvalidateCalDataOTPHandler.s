#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD= invalidateCalDataOTP

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:sectionId:1:u:0
PARM_END:

# rsp
RSP= invalidateCalDataOTPRsp

# rsp parm
PARM_START:
UINT8:status:1:u:0
PARM_END:
