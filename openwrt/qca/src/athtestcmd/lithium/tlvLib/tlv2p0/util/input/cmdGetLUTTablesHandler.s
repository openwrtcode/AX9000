#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
#
# This is a sample .s file, not a real command
#

# cmd
CMD= GetLUTTables

# cmd parm
PARM_START:
UINT8:LUTdumpOption:1:u:1
UINT8:phyId:1:u:0
UINT16:chainMask:1:x:0x1
PARM_END:

# rsp
RSP= GetLUTTablesRsp

# rsp parm
PARM_START:
DATA4096:data4k:4096:x
UINT8:status:1:u:0
UINT8:phyId:1:u:0
UINT16:rspDataLen:1:u:0
PARM_END:
