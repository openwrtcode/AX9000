/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdSetPerChainPwrHandler.s
#include "tlv2Inc.h"
#include "cmdSetPerChainPwrHandler.h"

void* initSETPERCHAINPWROpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_SETPERCHAINPWR_PARMS  *pSETPERCHAINPWRParms = (CMD_SETPERCHAINPWR_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pSETPERCHAINPWRParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pSETPERCHAINPWRParms->pad1 = pParmDict[PARM_PAD1].v.valU8;
    pSETPERCHAINPWRParms->chainMask = pParmDict[PARM_CHAINMASK].v.valU16;
    memset(pSETPERCHAINPWRParms->powerValPerChain, 0, sizeof(pSETPERCHAINPWRParms->powerValPerChain));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pSETPERCHAINPWRParms->phyId)) - (A_UINT32)pSETPERCHAINPWRParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD1, (A_UINT32)(((A_UINT32)&(pSETPERCHAINPWRParms->pad1)) - (A_UINT32)pSETPERCHAINPWRParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAINMASK, (A_UINT32)(((A_UINT32)&(pSETPERCHAINPWRParms->chainMask)) - (A_UINT32)pSETPERCHAINPWRParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_POWERVALPERCHAIN, (A_UINT32)(((A_UINT32)&(pSETPERCHAINPWRParms->powerValPerChain)) - (A_UINT32)pSETPERCHAINPWRParms), pParmsOffset);
    return((void*) pSETPERCHAINPWRParms);
}

static SETPERCHAINPWR_OP_FUNC SETPERCHAINPWROpFunc = NULL;

TLV2_API void registerSETPERCHAINPWRHandler(SETPERCHAINPWR_OP_FUNC fp)
{
    SETPERCHAINPWROpFunc = fp;
}

A_BOOL SETPERCHAINPWROp(void *pParms)
{
    CMD_SETPERCHAINPWR_PARMS *pSETPERCHAINPWRParms = (CMD_SETPERCHAINPWR_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("SETPERCHAINPWROp: phyId %u\n", pSETPERCHAINPWRParms->phyId);
    A_PRINTF("SETPERCHAINPWROp: pad1 %u\n", pSETPERCHAINPWRParms->pad1);
    A_PRINTF("SETPERCHAINPWROp: chainMask 0x%x\n", pSETPERCHAINPWRParms->chainMask);
    for (i = 0; i < 8 ; i++)
    {
        A_PRINTF("SETPERCHAINPWROp: powerValPerChain 0x%x\n", pSETPERCHAINPWRParms->powerValPerChain[i]);
    }
#endif //_DEBUG

    if (NULL != SETPERCHAINPWROpFunc) {
        (*SETPERCHAINPWROpFunc)(pSETPERCHAINPWRParms);
    }
    return(TRUE);
}

void* initSETPERCHAINPWRRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_SETPERCHAINPWRRSP_PARMS  *pSETPERCHAINPWRRSPParms = (CMD_SETPERCHAINPWRRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pSETPERCHAINPWRRSPParms->status = pParmDict[PARM_STATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pSETPERCHAINPWRRSPParms->status)) - (A_UINT32)pSETPERCHAINPWRRSPParms), pParmsOffset);
    return((void*) pSETPERCHAINPWRRSPParms);
}

static SETPERCHAINPWRRSP_OP_FUNC SETPERCHAINPWRRSPOpFunc = NULL;

TLV2_API void registerSETPERCHAINPWRRSPHandler(SETPERCHAINPWRRSP_OP_FUNC fp)
{
    SETPERCHAINPWRRSPOpFunc = fp;
}

A_BOOL SETPERCHAINPWRRSPOp(void *pParms)
{
    CMD_SETPERCHAINPWRRSP_PARMS *pSETPERCHAINPWRRSPParms = (CMD_SETPERCHAINPWRRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("SETPERCHAINPWRRSPOp: status %u\n", pSETPERCHAINPWRRSPParms->status);
#endif //_DEBUG

    if (NULL != SETPERCHAINPWRRSPOpFunc) {
        (*SETPERCHAINPWRRSPOpFunc)(pSETPERCHAINPWRRSPParms);
    }
    return(TRUE);
}
