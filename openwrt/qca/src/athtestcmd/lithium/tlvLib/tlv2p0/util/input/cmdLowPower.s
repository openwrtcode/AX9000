#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD= LowPower

# cmd parm
PARM_START:
UINT8:lowPowerMode:1:u:0
UINT8:phyIdMask:1:u:1
UINT32:lowPowerFeatureMask:1:x:0xffffffff
PARM_END:

