/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdSetLocalMacHandler.s
#include "tlv2Inc.h"
#include "cmdSetLocalMacHandler.h"

void* initSETLOCALMACOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_SETLOCALMAC_PARMS  *pSETLOCALMACParms = (CMD_SETLOCALMAC_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pSETLOCALMACParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    memset(pSETLOCALMACParms->localMac, 0, sizeof(pSETLOCALMACParms->localMac));
    pSETLOCALMACParms->pad1 = pParmDict[PARM_PAD1].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pSETLOCALMACParms->phyId)) - (A_UINT32)pSETLOCALMACParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LOCALMAC, (A_UINT32)(((A_UINT32)&(pSETLOCALMACParms->localMac)) - (A_UINT32)pSETLOCALMACParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD1, (A_UINT32)(((A_UINT32)&(pSETLOCALMACParms->pad1)) - (A_UINT32)pSETLOCALMACParms), pParmsOffset);
    return((void*) pSETLOCALMACParms);
}

static SETLOCALMAC_OP_FUNC SETLOCALMACOpFunc = NULL;

TLV2_API void registerSETLOCALMACHandler(SETLOCALMAC_OP_FUNC fp)
{
    SETLOCALMACOpFunc = fp;
}

A_BOOL SETLOCALMACOp(void *pParms)
{
    CMD_SETLOCALMAC_PARMS *pSETLOCALMACParms = (CMD_SETLOCALMAC_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("SETLOCALMACOp: phyId %u\n", pSETLOCALMACParms->phyId);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 54 entries
    {
        A_PRINTF("SETLOCALMACOp: localMac 0x%x\n", pSETLOCALMACParms->localMac[i]);
    }
    A_PRINTF("SETLOCALMACOp: pad1 %u\n", pSETLOCALMACParms->pad1);
#endif //_DEBUG

    if (NULL != SETLOCALMACOpFunc) {
        (*SETLOCALMACOpFunc)(pSETLOCALMACParms);
    }
    return(TRUE);
}

void* initSETLOCALMACRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_SETLOCALMACRSP_PARMS  *pSETLOCALMACRSPParms = (CMD_SETLOCALMACRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pSETLOCALMACRSPParms->status = pParmDict[PARM_STATUS].v.valU32;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pSETLOCALMACRSPParms->status)) - (A_UINT32)pSETLOCALMACRSPParms), pParmsOffset);
    return((void*) pSETLOCALMACRSPParms);
}

static SETLOCALMACRSP_OP_FUNC SETLOCALMACRSPOpFunc = NULL;

TLV2_API void registerSETLOCALMACRSPHandler(SETLOCALMACRSP_OP_FUNC fp)
{
    SETLOCALMACRSPOpFunc = fp;
}

A_BOOL SETLOCALMACRSPOp(void *pParms)
{
    CMD_SETLOCALMACRSP_PARMS *pSETLOCALMACRSPParms = (CMD_SETLOCALMACRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("SETLOCALMACRSPOp: status %u\n", pSETLOCALMACRSPParms->status);
#endif //_DEBUG

    if (NULL != SETLOCALMACRSPOpFunc) {
        (*SETLOCALMACRSPOpFunc)(pSETLOCALMACRSPParms);
    }
    return(TRUE);
}
