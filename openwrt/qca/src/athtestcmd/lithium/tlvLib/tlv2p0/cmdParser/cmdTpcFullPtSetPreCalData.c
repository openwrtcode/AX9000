/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdTpcFullPtSetPreCalData.s
#include "tlv2Inc.h"
#include "cmdTpcFullPtSetPreCalData.h"

void* initTPCFULLPTSETPRECALDATAOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_TPCFULLPTSETPRECALDATA_PARMS  *pTPCFULLPTSETPRECALDATAParms = (CMD_TPCFULLPTSETPRECALDATA_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pTPCFULLPTSETPRECALDATAParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pTPCFULLPTSETPRECALDATAParms->overrideEnable = pParmDict[PARM_OVERRIDEENABLE].v.valU8;
    pTPCFULLPTSETPRECALDATAParms->band = pParmDict[PARM_BAND].v.valU8;
    pTPCFULLPTSETPRECALDATAParms->pad1 = pParmDict[PARM_PAD1].v.valU8;
    memset(pTPCFULLPTSETPRECALDATAParms->TpcFreqFullPt, 0, sizeof(pTPCFULLPTSETPRECALDATAParms->TpcFreqFullPt));
    memset(pTPCFULLPTSETPRECALDATAParms->TpcCalDataTgtPwr, 0, sizeof(pTPCFULLPTSETPRECALDATAParms->TpcCalDataTgtPwr));
    memset(pTPCFULLPTSETPRECALDATAParms->TpcCalRfGain, 0, sizeof(pTPCFULLPTSETPRECALDATAParms->TpcCalRfGain));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pTPCFULLPTSETPRECALDATAParms->phyId)) - (A_UINT32)pTPCFULLPTSETPRECALDATAParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OVERRIDEENABLE, (A_UINT32)(((A_UINT32)&(pTPCFULLPTSETPRECALDATAParms->overrideEnable)) - (A_UINT32)pTPCFULLPTSETPRECALDATAParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BAND, (A_UINT32)(((A_UINT32)&(pTPCFULLPTSETPRECALDATAParms->band)) - (A_UINT32)pTPCFULLPTSETPRECALDATAParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD1, (A_UINT32)(((A_UINT32)&(pTPCFULLPTSETPRECALDATAParms->pad1)) - (A_UINT32)pTPCFULLPTSETPRECALDATAParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TPCFREQFULLPT, (A_UINT32)(((A_UINT32)&(pTPCFULLPTSETPRECALDATAParms->TpcFreqFullPt)) - (A_UINT32)pTPCFULLPTSETPRECALDATAParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TPCCALDATATGTPWR, (A_UINT32)(((A_UINT32)&(pTPCFULLPTSETPRECALDATAParms->TpcCalDataTgtPwr)) - (A_UINT32)pTPCFULLPTSETPRECALDATAParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TPCCALRFGAIN, (A_UINT32)(((A_UINT32)&(pTPCFULLPTSETPRECALDATAParms->TpcCalRfGain)) - (A_UINT32)pTPCFULLPTSETPRECALDATAParms), pParmsOffset);
    return((void*) pTPCFULLPTSETPRECALDATAParms);
}

static TPCFULLPTSETPRECALDATA_OP_FUNC TPCFULLPTSETPRECALDATAOpFunc = NULL;

TLV2_API void registerTPCFULLPTSETPRECALDATAHandler(TPCFULLPTSETPRECALDATA_OP_FUNC fp)
{
    TPCFULLPTSETPRECALDATAOpFunc = fp;
}

A_BOOL TPCFULLPTSETPRECALDATAOp(void *pParms)
{
    CMD_TPCFULLPTSETPRECALDATA_PARMS *pTPCFULLPTSETPRECALDATAParms = (CMD_TPCFULLPTSETPRECALDATA_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("TPCFULLPTSETPRECALDATAOp: phyId %u\n", pTPCFULLPTSETPRECALDATAParms->phyId);
    A_PRINTF("TPCFULLPTSETPRECALDATAOp: overrideEnable %u\n", pTPCFULLPTSETPRECALDATAParms->overrideEnable);
    A_PRINTF("TPCFULLPTSETPRECALDATAOp: band %u\n", pTPCFULLPTSETPRECALDATAParms->band);
    A_PRINTF("TPCFULLPTSETPRECALDATAOp: pad1 %u\n", pTPCFULLPTSETPRECALDATAParms->pad1);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 32 entries
    {
        A_PRINTF("TPCFULLPTSETPRECALDATAOp: TpcFreqFullPt %u\n", pTPCFULLPTSETPRECALDATAParms->TpcFreqFullPt[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 32 entries
    {
        A_PRINTF("TPCFULLPTSETPRECALDATAOp: TpcCalDataTgtPwr %u\n", pTPCFULLPTSETPRECALDATAParms->TpcCalDataTgtPwr[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 32 entries
    {
        A_PRINTF("TPCFULLPTSETPRECALDATAOp: TpcCalRfGain %u\n", pTPCFULLPTSETPRECALDATAParms->TpcCalRfGain[i]);
    }
#endif //_DEBUG

    if (NULL != TPCFULLPTSETPRECALDATAOpFunc) {
        (*TPCFULLPTSETPRECALDATAOpFunc)(pTPCFULLPTSETPRECALDATAParms);
    }
    return(TRUE);
}

void* initTPCFULLPTSETPRECALDATARSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_TPCFULLPTSETPRECALDATARSP_PARMS  *pTPCFULLPTSETPRECALDATARSPParms = (CMD_TPCFULLPTSETPRECALDATARSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pTPCFULLPTSETPRECALDATARSPParms->status = pParmDict[PARM_STATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pTPCFULLPTSETPRECALDATARSPParms->status)) - (A_UINT32)pTPCFULLPTSETPRECALDATARSPParms), pParmsOffset);
    return((void*) pTPCFULLPTSETPRECALDATARSPParms);
}

static TPCFULLPTSETPRECALDATARSP_OP_FUNC TPCFULLPTSETPRECALDATARSPOpFunc = NULL;

TLV2_API void registerTPCFULLPTSETPRECALDATARSPHandler(TPCFULLPTSETPRECALDATARSP_OP_FUNC fp)
{
    TPCFULLPTSETPRECALDATARSPOpFunc = fp;
}

A_BOOL TPCFULLPTSETPRECALDATARSPOp(void *pParms)
{
    CMD_TPCFULLPTSETPRECALDATARSP_PARMS *pTPCFULLPTSETPRECALDATARSPParms = (CMD_TPCFULLPTSETPRECALDATARSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("TPCFULLPTSETPRECALDATARSPOp: status %u\n", pTPCFULLPTSETPRECALDATARSPParms->status);
#endif //_DEBUG

    if (NULL != TPCFULLPTSETPRECALDATARSPOpFunc) {
        (*TPCFULLPTSETPRECALDATARSPOpFunc)(pTPCFULLPTSETPRECALDATARSPParms);
    }
    return(TRUE);
}
