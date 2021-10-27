#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
#cmd
CMD = RADARDETECT

#cmd parm
PARM_START:
UINT16: freq : 1 : u : 0
UINT16: freq2 : 1 : u : 0
UINT16: regDmn : 2 : x : 0x00 : 0x00
UINT16: duration : 1 : u : 0
UINT8: phyId : 1 : u : 0
UINT8: bandwidth : 1 : u : 0
PARM_END:

#rsp
      RSP = RADARDETECTRSP

#rsp parm
PARM_START:
UINT32:     numRadarEvents : 1 : u : 0
PARM_END:
