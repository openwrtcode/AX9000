#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD= WriteCalDataToOTP

# cmd parm
PARM_START:
UINT8:phyID:1:u:0
PARM_END:

# rsp
RSP= WriteCalDataToOTPRsp

# rsp parm
PARM_START:
UINT8:status:1:u:0
PARM_END: