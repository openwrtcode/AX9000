/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdTpc1PtSetChanPwr.s
#include "tlv2Inc.h"
#include "cmdTpc1PtSetChanPwr.h"

void* initTPC1PTSETCHANPWROpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_TPC1PTSETCHANPWR_PARMS  *pTPC1PTSETCHANPWRParms = (CMD_TPC1PTSETCHANPWR_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pTPC1PTSETCHANPWRParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pTPC1PTSETCHANPWRParms->chainIdx = pParmDict[PARM_CHAINIDX].v.valU8;
    pTPC1PTSETCHANPWRParms->overrideEnable = pParmDict[PARM_OVERRIDEENABLE].v.valU8;
    pTPC1PTSETCHANPWRParms->pad1 = pParmDict[PARM_PAD1].v.valU8;
    memset(pTPC1PTSETCHANPWRParms->TpcFreq, 0, sizeof(pTPC1PTSETCHANPWRParms->TpcFreq));
    memset(pTPC1PTSETCHANPWRParms->TpcPwr, 0, sizeof(pTPC1PTSETCHANPWRParms->TpcPwr));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pTPC1PTSETCHANPWRParms->phyId)) - (A_UINT32)pTPC1PTSETCHANPWRParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAINIDX, (A_UINT32)(((A_UINT32)&(pTPC1PTSETCHANPWRParms->chainIdx)) - (A_UINT32)pTPC1PTSETCHANPWRParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OVERRIDEENABLE, (A_UINT32)(((A_UINT32)&(pTPC1PTSETCHANPWRParms->overrideEnable)) - (A_UINT32)pTPC1PTSETCHANPWRParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD1, (A_UINT32)(((A_UINT32)&(pTPC1PTSETCHANPWRParms->pad1)) - (A_UINT32)pTPC1PTSETCHANPWRParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TPCFREQ, (A_UINT32)(((A_UINT32)&(pTPC1PTSETCHANPWRParms->TpcFreq)) - (A_UINT32)pTPC1PTSETCHANPWRParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TPCPWR, (A_UINT32)(((A_UINT32)&(pTPC1PTSETCHANPWRParms->TpcPwr)) - (A_UINT32)pTPC1PTSETCHANPWRParms), pParmsOffset);
    return((void*) pTPC1PTSETCHANPWRParms);
}

static TPC1PTSETCHANPWR_OP_FUNC TPC1PTSETCHANPWROpFunc = NULL;

TLV2_API void registerTPC1PTSETCHANPWRHandler(TPC1PTSETCHANPWR_OP_FUNC fp)
{
    TPC1PTSETCHANPWROpFunc = fp;
}

A_BOOL TPC1PTSETCHANPWROp(void *pParms)
{
    CMD_TPC1PTSETCHANPWR_PARMS *pTPC1PTSETCHANPWRParms = (CMD_TPC1PTSETCHANPWR_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("TPC1PTSETCHANPWROp: phyId %u\n", pTPC1PTSETCHANPWRParms->phyId);
    A_PRINTF("TPC1PTSETCHANPWROp: chainIdx %u\n", pTPC1PTSETCHANPWRParms->chainIdx);
    A_PRINTF("TPC1PTSETCHANPWROp: overrideEnable %u\n", pTPC1PTSETCHANPWRParms->overrideEnable);
    A_PRINTF("TPC1PTSETCHANPWROp: pad1 %u\n", pTPC1PTSETCHANPWRParms->pad1);
    for (i = 0; i < 8 ; i++)
    {
        A_PRINTF("TPC1PTSETCHANPWROp: TpcFreq %u\n", pTPC1PTSETCHANPWRParms->TpcFreq[i]);
    }
    for (i = 0; i < 8 ; i++)
    {
        A_PRINTF("TPC1PTSETCHANPWROp: TpcPwr %u\n", pTPC1PTSETCHANPWRParms->TpcPwr[i]);
    }
#endif //_DEBUG

    if (NULL != TPC1PTSETCHANPWROpFunc) {
        (*TPC1PTSETCHANPWROpFunc)(pTPC1PTSETCHANPWRParms);
    }
    return(TRUE);
}

void* initTPC1PTSETCHANPWRRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_TPC1PTSETCHANPWRRSP_PARMS  *pTPC1PTSETCHANPWRRSPParms = (CMD_TPC1PTSETCHANPWRRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pTPC1PTSETCHANPWRRSPParms->status = pParmDict[PARM_STATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pTPC1PTSETCHANPWRRSPParms->status)) - (A_UINT32)pTPC1PTSETCHANPWRRSPParms), pParmsOffset);
    return((void*) pTPC1PTSETCHANPWRRSPParms);
}

static TPC1PTSETCHANPWRRSP_OP_FUNC TPC1PTSETCHANPWRRSPOpFunc = NULL;

TLV2_API void registerTPC1PTSETCHANPWRRSPHandler(TPC1PTSETCHANPWRRSP_OP_FUNC fp)
{
    TPC1PTSETCHANPWRRSPOpFunc = fp;
}

A_BOOL TPC1PTSETCHANPWRRSPOp(void *pParms)
{
    CMD_TPC1PTSETCHANPWRRSP_PARMS *pTPC1PTSETCHANPWRRSPParms = (CMD_TPC1PTSETCHANPWRRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("TPC1PTSETCHANPWRRSPOp: status %u\n", pTPC1PTSETCHANPWRRSPParms->status);
#endif //_DEBUG

    if (NULL != TPC1PTSETCHANPWRRSPOpFunc) {
        (*TPC1PTSETCHANPWRRSPOpFunc)(pTPC1PTSETCHANPWRRSPParms);
    }
    return(TRUE);
}
