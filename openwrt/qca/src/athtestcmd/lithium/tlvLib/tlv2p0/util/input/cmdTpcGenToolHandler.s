#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
CMD= TpcGenTool

# cmd parm
PARM_START:
UINT32:countryCode:1:u:0
UINT32:regDomain:1:u:0
INT32:ctl:1:u:0
INT8:sarIndex:1:u:0
UINT8:phyMode:1:u:0
UINT8:beamforming:1:u:0
UINT8:ctlrd:1:u:0
UINT16:freq:1:u:0
UINT8:chainIdx:1:u:0
UINT8:chainMask:1:u:0
UINT16:rate:1:u:0
UINT32:nss:1:u:0
PARM_END:

# rsp
RSP= TpcGenToolRsp

# rsp parm
PARM_START:
UINT8:tpcPower:1:u:8
UINT8:RegDmnFW:1:u:0
UINT8:status:1:u:0
PARM_END: