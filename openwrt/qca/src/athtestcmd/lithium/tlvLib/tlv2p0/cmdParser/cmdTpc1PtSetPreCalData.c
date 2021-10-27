/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdTpc1PtSetPreCalData.s
#include "tlv2Inc.h"
#include "cmdTpc1PtSetPreCalData.h"

void* initTPC1PTSETPRECALDATAOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_TPC1PTSETPRECALDATA_PARMS  *pTPC1PTSETPRECALDATAParms = (CMD_TPC1PTSETPRECALDATA_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pTPC1PTSETPRECALDATAParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pTPC1PTSETPRECALDATAParms->calOffsetPower = pParmDict[PARM_CALOFFSETPOWER].v.valU8;
    pTPC1PTSETPRECALDATAParms->overrideEnable = pParmDict[PARM_OVERRIDEENABLE].v.valU8;
    pTPC1PTSETPRECALDATAParms->band = pParmDict[PARM_BAND].v.valU8;
    memset(pTPC1PTSETPRECALDATAParms->TpcFreq, 0, sizeof(pTPC1PTSETPRECALDATAParms->TpcFreq));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pTPC1PTSETPRECALDATAParms->phyId)) - (A_UINT32)pTPC1PTSETPRECALDATAParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CALOFFSETPOWER, (A_UINT32)(((A_UINT32)&(pTPC1PTSETPRECALDATAParms->calOffsetPower)) - (A_UINT32)pTPC1PTSETPRECALDATAParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OVERRIDEENABLE, (A_UINT32)(((A_UINT32)&(pTPC1PTSETPRECALDATAParms->overrideEnable)) - (A_UINT32)pTPC1PTSETPRECALDATAParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BAND, (A_UINT32)(((A_UINT32)&(pTPC1PTSETPRECALDATAParms->band)) - (A_UINT32)pTPC1PTSETPRECALDATAParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TPCFREQ, (A_UINT32)(((A_UINT32)&(pTPC1PTSETPRECALDATAParms->TpcFreq)) - (A_UINT32)pTPC1PTSETPRECALDATAParms), pParmsOffset);
    return((void*) pTPC1PTSETPRECALDATAParms);
}

static TPC1PTSETPRECALDATA_OP_FUNC TPC1PTSETPRECALDATAOpFunc = NULL;

TLV2_API void registerTPC1PTSETPRECALDATAHandler(TPC1PTSETPRECALDATA_OP_FUNC fp)
{
    TPC1PTSETPRECALDATAOpFunc = fp;
}

A_BOOL TPC1PTSETPRECALDATAOp(void *pParms)
{
    CMD_TPC1PTSETPRECALDATA_PARMS *pTPC1PTSETPRECALDATAParms = (CMD_TPC1PTSETPRECALDATA_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("TPC1PTSETPRECALDATAOp: phyId %u\n", pTPC1PTSETPRECALDATAParms->phyId);
    A_PRINTF("TPC1PTSETPRECALDATAOp: calOffsetPower %u\n", pTPC1PTSETPRECALDATAParms->calOffsetPower);
    A_PRINTF("TPC1PTSETPRECALDATAOp: overrideEnable %u\n", pTPC1PTSETPRECALDATAParms->overrideEnable);
    A_PRINTF("TPC1PTSETPRECALDATAOp: band %u\n", pTPC1PTSETPRECALDATAParms->band);
    for (i = 0; i < 8 ; i++)
    {
        A_PRINTF("TPC1PTSETPRECALDATAOp: TpcFreq %u\n", pTPC1PTSETPRECALDATAParms->TpcFreq[i]);
    }
#endif //_DEBUG

    if (NULL != TPC1PTSETPRECALDATAOpFunc) {
        (*TPC1PTSETPRECALDATAOpFunc)(pTPC1PTSETPRECALDATAParms);
    }
    return(TRUE);
}

void* initTPC1PTSETPRECALDATARSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_TPC1PTSETPRECALDATARSP_PARMS  *pTPC1PTSETPRECALDATARSPParms = (CMD_TPC1PTSETPRECALDATARSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pTPC1PTSETPRECALDATARSPParms->status = pParmDict[PARM_STATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pTPC1PTSETPRECALDATARSPParms->status)) - (A_UINT32)pTPC1PTSETPRECALDATARSPParms), pParmsOffset);
    return((void*) pTPC1PTSETPRECALDATARSPParms);
}

static TPC1PTSETPRECALDATARSP_OP_FUNC TPC1PTSETPRECALDATARSPOpFunc = NULL;

TLV2_API void registerTPC1PTSETPRECALDATARSPHandler(TPC1PTSETPRECALDATARSP_OP_FUNC fp)
{
    TPC1PTSETPRECALDATARSPOpFunc = fp;
}

A_BOOL TPC1PTSETPRECALDATARSPOp(void *pParms)
{
    CMD_TPC1PTSETPRECALDATARSP_PARMS *pTPC1PTSETPRECALDATARSPParms = (CMD_TPC1PTSETPRECALDATARSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("TPC1PTSETPRECALDATARSPOp: status %u\n", pTPC1PTSETPRECALDATARSPParms->status);
#endif //_DEBUG

    if (NULL != TPC1PTSETPRECALDATARSPOpFunc) {
        (*TPC1PTSETPRECALDATARSPOpFunc)(pTPC1PTSETPRECALDATARSPParms);
    }
    return(TRUE);
}
