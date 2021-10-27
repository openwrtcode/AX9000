/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdBdGetIbfCalInfo.s
#include "tlv2Inc.h"
#include "cmdBdGetIbfCalInfo.h"

void* initBDGETIBFCALINFOOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_BDGETIBFCALINFO_PARMS  *pBDGETIBFCALINFOParms = (CMD_BDGETIBFCALINFO_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pBDGETIBFCALINFOParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pBDGETIBFCALINFOParms->phyId)) - (A_UINT32)pBDGETIBFCALINFOParms), pParmsOffset);
    return((void*) pBDGETIBFCALINFOParms);
}

static BDGETIBFCALINFO_OP_FUNC BDGETIBFCALINFOOpFunc = NULL;

TLV2_API void registerBDGETIBFCALINFOHandler(BDGETIBFCALINFO_OP_FUNC fp)
{
    BDGETIBFCALINFOOpFunc = fp;
}

A_BOOL BDGETIBFCALINFOOp(void *pParms)
{
    CMD_BDGETIBFCALINFO_PARMS *pBDGETIBFCALINFOParms = (CMD_BDGETIBFCALINFO_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("BDGETIBFCALINFOOp: phyId %u\n", pBDGETIBFCALINFOParms->phyId);
#endif //_DEBUG

    if (NULL != BDGETIBFCALINFOOpFunc) {
        (*BDGETIBFCALINFOOpFunc)(pBDGETIBFCALINFOParms);
    }
    return(TRUE);
}

void* initBDGETIBFCALINFORSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_BDGETIBFCALINFORSP_PARMS  *pBDGETIBFCALINFORSPParms = (CMD_BDGETIBFCALINFORSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pBDGETIBFCALINFORSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    pBDGETIBFCALINFORSPParms->numFreq = pParmDict[PARM_NUMFREQ].v.valU8;
    pBDGETIBFCALINFORSPParms->numChain = pParmDict[PARM_NUMCHAIN].v.valU8;
    pBDGETIBFCALINFORSPParms->pad1 = pParmDict[PARM_PAD1].v.valU8;
    pBDGETIBFCALINFORSPParms->freqOffset = pParmDict[PARM_FREQOFFSET].v.valU32;
    pBDGETIBFCALINFORSPParms->ibfCalDataOffset = pParmDict[PARM_IBFCALDATAOFFSET].v.valU32;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pBDGETIBFCALINFORSPParms->status)) - (A_UINT32)pBDGETIBFCALINFORSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMFREQ, (A_UINT32)(((A_UINT32)&(pBDGETIBFCALINFORSPParms->numFreq)) - (A_UINT32)pBDGETIBFCALINFORSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMCHAIN, (A_UINT32)(((A_UINT32)&(pBDGETIBFCALINFORSPParms->numChain)) - (A_UINT32)pBDGETIBFCALINFORSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD1, (A_UINT32)(((A_UINT32)&(pBDGETIBFCALINFORSPParms->pad1)) - (A_UINT32)pBDGETIBFCALINFORSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FREQOFFSET, (A_UINT32)(((A_UINT32)&(pBDGETIBFCALINFORSPParms->freqOffset)) - (A_UINT32)pBDGETIBFCALINFORSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_IBFCALDATAOFFSET, (A_UINT32)(((A_UINT32)&(pBDGETIBFCALINFORSPParms->ibfCalDataOffset)) - (A_UINT32)pBDGETIBFCALINFORSPParms), pParmsOffset);
    return((void*) pBDGETIBFCALINFORSPParms);
}

static BDGETIBFCALINFORSP_OP_FUNC BDGETIBFCALINFORSPOpFunc = NULL;

TLV2_API void registerBDGETIBFCALINFORSPHandler(BDGETIBFCALINFORSP_OP_FUNC fp)
{
    BDGETIBFCALINFORSPOpFunc = fp;
}

A_BOOL BDGETIBFCALINFORSPOp(void *pParms)
{
    CMD_BDGETIBFCALINFORSP_PARMS *pBDGETIBFCALINFORSPParms = (CMD_BDGETIBFCALINFORSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("BDGETIBFCALINFORSPOp: status %u\n", pBDGETIBFCALINFORSPParms->status);
    A_PRINTF("BDGETIBFCALINFORSPOp: numFreq %u\n", pBDGETIBFCALINFORSPParms->numFreq);
    A_PRINTF("BDGETIBFCALINFORSPOp: numChain %u\n", pBDGETIBFCALINFORSPParms->numChain);
    A_PRINTF("BDGETIBFCALINFORSPOp: pad1 0x%x\n", pBDGETIBFCALINFORSPParms->pad1);
    A_PRINTF("BDGETIBFCALINFORSPOp: freqOffset %u\n", pBDGETIBFCALINFORSPParms->freqOffset);
    A_PRINTF("BDGETIBFCALINFORSPOp: ibfCalDataOffset %u\n", pBDGETIBFCALINFORSPParms->ibfCalDataOffset);
#endif //_DEBUG

    if (NULL != BDGETIBFCALINFORSPOpFunc) {
        (*BDGETIBFCALINFORSPOpFunc)(pBDGETIBFCALINFORSPParms);
    }
    return(TRUE);
}
