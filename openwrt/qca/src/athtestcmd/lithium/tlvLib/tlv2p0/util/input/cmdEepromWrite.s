#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD= EepromWrite

# cmd parm
PARM_START:
UINT32:offset:1:u:0
UINT32:size:1:u:0
DATA4096:data4k:4096:x
PARM_END:

