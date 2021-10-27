#===============================================================================
# Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================
#ifndef MAX_NUM_OF_BURSTS
#define MAX_NUM_OF_BURSTS 25 
#endif
#ifndef BURST_PDADCVALUE_ARRAY_MAX_LEN
#define BURST_PDADCVALUE_ARRAY_MAX_LEN 35 
#endif

# cmd
CMD= RxQueryReq

# cmd parm
PARM_START:
UINT8:requestId:1:u:0
INT8:burstId:1:d:0
PARM_END:

# cmd
RSP= RxQueryReqRsp

# cmd parm
PARM_START:
UINT8:requestId:1:u:0
UINT8:status:1:u:0
UINT8:rxQueryStatus:1:u:3	#default state is RX_QUERY_SUCCESS
UINT8:numOfResults:1:u:1
UINT16:burst_PdAdcValue:BURST_PDADCVALUE_ARRAY_MAX_LEN:35:u		#In each 2Byte value 1st Byte filled with BurstId and 2nd Byte with PDADC value.
PARM_END:
