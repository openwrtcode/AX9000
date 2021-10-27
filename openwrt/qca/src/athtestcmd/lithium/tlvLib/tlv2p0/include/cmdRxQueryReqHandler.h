/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdRxQueryReqHandler.s
#ifndef _CMDRXQUERYREQHANDLER_H_
#define _CMDRXQUERYREQHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

#ifndef MAX_NUM_OF_BURSTS
#define MAX_NUM_OF_BURSTS 25 
#endif
#ifndef BURST_PDADCVALUE_ARRAY_MAX_LEN
#define BURST_PDADCVALUE_ARRAY_MAX_LEN 35 
#endif

typedef struct rxqueryreq_parms {
    A_UINT8	requestId;
    A_INT8	burstId;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_RXQUERYREQ_PARMS;

typedef struct rxqueryreqrsp_parms {
    A_UINT8	requestId;
    A_UINT8	status;
    A_UINT8	rxQueryStatus;
    A_UINT8	numOfResults;
    A_UINT16	burst_PdAdcValue[BURST_PDADCVALUE_ARRAY_MAX_LEN];
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_RXQUERYREQRSP_PARMS;

typedef void (*RXQUERYREQ_OP_FUNC)(void *pParms);
typedef void (*RXQUERYREQRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initRXQUERYREQOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RXQUERYREQOp(void *pParms);

void* initRXQUERYREQRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RXQUERYREQRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDRXQUERYREQHANDLER_H_
