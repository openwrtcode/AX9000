#===============================================================================
# Copyright (c) 2017-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================

# cmd
CMD= rxgaincal

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:chainIdx:1:u:0
UINT8:band:1:u:0
UINT8:radioId:1:u:0
UINT8:bssid:6:x:0x01:0x00:0x00:0xCA:0xFF:0xEE
UINT8:staAddr:6:x:0x00:0x03:0x7F:0x11:0x12:0x13
UINT8:rxMode:1:u:0
UINT16:freq:1:u:0
PARM_END:

# rsp
RSP= rxgaincalrsp
# rsp param
PARM_START:
UINT8:phyId:1:u:0
UINT8:status:1:u:0
UINT8:band:1:u:0
INT8:refISS:1:u:0
UINT8:rate:1:u:0
UINT8:bandWidth:1:u:0
UINT8:chanIdx:1:u:0
UINT8:chainIdx:1:u:0
UINT16:numPackets:1:u:0
UINT16:freq:1:u:0
UINT8:radioId:1:u:0
PARM_END:
