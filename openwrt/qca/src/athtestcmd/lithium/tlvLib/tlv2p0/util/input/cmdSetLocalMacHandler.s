#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD= SetLocalMac

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:localMac:54:x
UINT8:pad1:1:u
PARM_END:

# rsp
RSP= SetLocalMacRsp

# rsp parm
PARM_START:
UINT32:status:1:u:0
PARM_END:


