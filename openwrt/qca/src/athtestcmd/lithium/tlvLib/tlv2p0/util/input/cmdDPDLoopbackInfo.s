#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
# cmd
CMD= dpdLoopbackInfo

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT16:chainMask:1:x:0x3
PARM_END:

# rsp
RSP= dpdLoopbackInfoRsp

# rsp parm
PARM_START:
UINT8:status:1:u:0
UINT8:phyId:1:u:0
UINT16:chainMask:1:x:0x3
UINT8:dpd_lb_fail:1:u:0
UINT8:rx_gain:1:u:0
UINT8:max_bin:1:u:0
INT8:max_bin_db:1:u:0
INT16:agc2_pwr:1:u:0
INT16:dc_i:1:u:0
INT16:dc_q:1:u:0 
UINT16:sq:1:u:0
UINT8:sq_idx:1:u:0
PARM_END:
