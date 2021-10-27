#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD= VerifyCalDb

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:calType:1:u:0
PARM_END:

# rsp
RSP= VerifyCalDbRsp

# rsp parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:status:1:u:0
PARM_END:
