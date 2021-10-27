/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdRxQueryReqHandler.s
#include "tlv2Inc.h"
#include "cmdRxQueryReqHandler.h"

void* initRXQUERYREQOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_RXQUERYREQ_PARMS  *pRXQUERYREQParms = (CMD_RXQUERYREQ_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pRXQUERYREQParms->requestId = pParmDict[PARM_REQUESTID].v.valU8;
    pRXQUERYREQParms->burstId = pParmDict[PARM_BURSTID].v.valS8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_REQUESTID, (A_UINT32)(((A_UINT32)&(pRXQUERYREQParms->requestId)) - (A_UINT32)pRXQUERYREQParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BURSTID, (A_UINT32)(((A_UINT32)&(pRXQUERYREQParms->burstId)) - (A_UINT32)pRXQUERYREQParms), pParmsOffset);
    return((void*) pRXQUERYREQParms);
}

static RXQUERYREQ_OP_FUNC RXQUERYREQOpFunc = NULL;

TLV2_API void registerRXQUERYREQHandler(RXQUERYREQ_OP_FUNC fp)
{
    RXQUERYREQOpFunc = fp;
}

A_BOOL RXQUERYREQOp(void *pParms)
{
    CMD_RXQUERYREQ_PARMS *pRXQUERYREQParms = (CMD_RXQUERYREQ_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("RXQUERYREQOp: requestId %u\n", pRXQUERYREQParms->requestId);
    A_PRINTF("RXQUERYREQOp: burstId %d\n", pRXQUERYREQParms->burstId);
#endif //_DEBUG

    if (NULL != RXQUERYREQOpFunc) {
        (*RXQUERYREQOpFunc)(pRXQUERYREQParms);
    }
    return(TRUE);
}

void* initRXQUERYREQRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_RXQUERYREQRSP_PARMS  *pRXQUERYREQRSPParms = (CMD_RXQUERYREQRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pRXQUERYREQRSPParms->requestId = pParmDict[PARM_REQUESTID].v.valU8;
    pRXQUERYREQRSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pRXQUERYREQRSPParms->rxQueryStatus = pParmDict[PARM_RXQUERYSTATUS].v.valU8;
    pRXQUERYREQRSPParms->numOfResults = pParmDict[PARM_NUMOFRESULTS].v.valU8;
    memset(pRXQUERYREQRSPParms->burst_PdAdcValue, 0, sizeof(pRXQUERYREQRSPParms->burst_PdAdcValue));
    for (i = 0; i < 15 ; i++)
    {
        pRXQUERYREQRSPParms->burst_PdAdcValue[i] = pParmDict[PARM_BURST_PDADCVALUE].v.ptU16[i];
    }

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_REQUESTID, (A_UINT32)(((A_UINT32)&(pRXQUERYREQRSPParms->requestId)) - (A_UINT32)pRXQUERYREQRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pRXQUERYREQRSPParms->status)) - (A_UINT32)pRXQUERYREQRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RXQUERYSTATUS, (A_UINT32)(((A_UINT32)&(pRXQUERYREQRSPParms->rxQueryStatus)) - (A_UINT32)pRXQUERYREQRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMOFRESULTS, (A_UINT32)(((A_UINT32)&(pRXQUERYREQRSPParms->numOfResults)) - (A_UINT32)pRXQUERYREQRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BURST_PDADCVALUE, (A_UINT32)(((A_UINT32)&(pRXQUERYREQRSPParms->burst_PdAdcValue)) - (A_UINT32)pRXQUERYREQRSPParms), pParmsOffset);
    return((void*) pRXQUERYREQRSPParms);
}

static RXQUERYREQRSP_OP_FUNC RXQUERYREQRSPOpFunc = NULL;

TLV2_API void registerRXQUERYREQRSPHandler(RXQUERYREQRSP_OP_FUNC fp)
{
    RXQUERYREQRSPOpFunc = fp;
}

A_BOOL RXQUERYREQRSPOp(void *pParms)
{
    CMD_RXQUERYREQRSP_PARMS *pRXQUERYREQRSPParms = (CMD_RXQUERYREQRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("RXQUERYREQRSPOp: requestId %u\n", pRXQUERYREQRSPParms->requestId);
    A_PRINTF("RXQUERYREQRSPOp: status %u\n", pRXQUERYREQRSPParms->status);
    A_PRINTF("RXQUERYREQRSPOp: rxQueryStatus %u\n", pRXQUERYREQRSPParms->rxQueryStatus);
    A_PRINTF("RXQUERYREQRSPOp: numOfResults %u\n", pRXQUERYREQRSPParms->numOfResults);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 35 entries
    {
        A_PRINTF("RXQUERYREQRSPOp: burst_PdAdcValue %u\n", pRXQUERYREQRSPParms->burst_PdAdcValue[i]);
    }
#endif //_DEBUG

    if (NULL != RXQUERYREQRSPOpFunc) {
        (*RXQUERYREQRSPOpFunc)(pRXQUERYREQRSPParms);
    }
    return(TRUE);
}
