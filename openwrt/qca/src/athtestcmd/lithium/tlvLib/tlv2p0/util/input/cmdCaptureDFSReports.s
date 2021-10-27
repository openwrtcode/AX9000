#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
#cmd
CMD = CAPTUREDFSREPORTS

#cmd parm
PARM_START:
UINT32: offset : 1 : u : 0            #indicates the offset from which the response needs to be send to QDART
UINT32: numRadarEvents : 1 : u : 0    #indicates the number of events to read in response to this command
UINT8: phyId : 1 : u : 0
PARM_END:

#rsp
      RSP = CAPTUREDFSREPORTSRSP

#rsp parm
PARM_START:
UINT32:     dfsStatus : 1 : u : 0
UINT32:     detection_mode : 1000 : u : 0 : repeat : 999 : 1 : 0
UINT32:     chan_freq : 1000 : u : 0 : repeat : 999 : 1 : 0
UINT32:     radar_freq : 1000 : u : 0 : repeat : 999 : 1 : 0
UINT32:     chan_width : 1000 : u : 0 : repeat : 999 : 1 : 0
UINT32:     detector_id : 1000 : u : 0 : repeat : 999 : 1 : 0
UINT32:     timestamp : 1000 : u : 0 : repeat : 999 : 1 : 0
UINT32:     segment_id : 1000 : u : 0 : repeat : 999 : 1 : 0
UINT32:     is_chirp : 1000 : u : 0 : repeat : 999 : 1 : 0
INT32:      freq_offset : 1000 : d : 0 : repeat : 999 : 1 : 0
INT32:      sidx : 1000 : d : 0 : repeat : 999 : 1 : 0
PARM_END:
