/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdSetBoardMcnHandler.s
#include "tlv2Inc.h"
#include "cmdSetBoardMcnHandler.h"

void* initSETBOARDMCNOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_SETBOARDMCN_PARMS  *pSETBOARDMCNParms = (CMD_SETBOARDMCN_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pSETBOARDMCNParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    memset(pSETBOARDMCNParms->boardMcn, 0, sizeof(pSETBOARDMCNParms->boardMcn));
    memset(pSETBOARDMCNParms->pad3, 0, sizeof(pSETBOARDMCNParms->pad3));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pSETBOARDMCNParms->phyId)) - (A_UINT32)pSETBOARDMCNParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BOARDMCN, (A_UINT32)(((A_UINT32)&(pSETBOARDMCNParms->boardMcn)) - (A_UINT32)pSETBOARDMCNParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD3, (A_UINT32)(((A_UINT32)&(pSETBOARDMCNParms->pad3)) - (A_UINT32)pSETBOARDMCNParms), pParmsOffset);
    return((void*) pSETBOARDMCNParms);
}

static SETBOARDMCN_OP_FUNC SETBOARDMCNOpFunc = NULL;

TLV2_API void registerSETBOARDMCNHandler(SETBOARDMCN_OP_FUNC fp)
{
    SETBOARDMCNOpFunc = fp;
}

A_BOOL SETBOARDMCNOp(void *pParms)
{
    CMD_SETBOARDMCN_PARMS *pSETBOARDMCNParms = (CMD_SETBOARDMCN_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("SETBOARDMCNOp: phyId %u\n", pSETBOARDMCNParms->phyId);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 20 entries
    {
        A_PRINTF("SETBOARDMCNOp: boardMcn %u\n", pSETBOARDMCNParms->boardMcn[i]);
    }
    for (i = 0; i < 3 ; i++)
    {
        A_PRINTF("SETBOARDMCNOp: pad3 %u\n", pSETBOARDMCNParms->pad3[i]);
    }
#endif //_DEBUG

    if (NULL != SETBOARDMCNOpFunc) {
        (*SETBOARDMCNOpFunc)(pSETBOARDMCNParms);
    }
    return(TRUE);
}

void* initSETBOARDMCNRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_SETBOARDMCNRSP_PARMS  *pSETBOARDMCNRSPParms = (CMD_SETBOARDMCNRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pSETBOARDMCNRSPParms->status = pParmDict[PARM_STATUS].v.valU32;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pSETBOARDMCNRSPParms->status)) - (A_UINT32)pSETBOARDMCNRSPParms), pParmsOffset);
    return((void*) pSETBOARDMCNRSPParms);
}

static SETBOARDMCNRSP_OP_FUNC SETBOARDMCNRSPOpFunc = NULL;

TLV2_API void registerSETBOARDMCNRSPHandler(SETBOARDMCNRSP_OP_FUNC fp)
{
    SETBOARDMCNRSPOpFunc = fp;
}

A_BOOL SETBOARDMCNRSPOp(void *pParms)
{
    CMD_SETBOARDMCNRSP_PARMS *pSETBOARDMCNRSPParms = (CMD_SETBOARDMCNRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("SETBOARDMCNRSPOp: status %u\n", pSETBOARDMCNRSPParms->status);
#endif //_DEBUG

    if (NULL != SETBOARDMCNRSPOpFunc) {
        (*SETBOARDMCNRSPOpFunc)(pSETBOARDMCNRSPParms);
    }
    return(TRUE);
}
