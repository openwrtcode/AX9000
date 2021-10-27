#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD= setBoardMcn

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:boardMcn:20:u
UINT8:pad3:3:u
PARM_END:

# rsp
RSP= setBoardMcnRsp

# rsp parm
PARM_START:
UINT32:status:1:u:0
PARM_END:
