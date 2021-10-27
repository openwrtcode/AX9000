/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdCaptureFFTReports.s
#include "tlv2Inc.h"
#include "cmdCaptureFFTReports.h"

void* initCAPTUREFFTREPORTSOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_CAPTUREFFTREPORTS_PARMS  *pCAPTUREFFTREPORTSParms = (CMD_CAPTUREFFTREPORTS_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pCAPTUREFFTREPORTSParms->fftreportsize = pParmDict[PARM_FFTREPORTSIZE].v.valU32;
    pCAPTUREFFTREPORTSParms->offset = pParmDict[PARM_OFFSET].v.valU32;
    pCAPTUREFFTREPORTSParms->size = pParmDict[PARM_SIZE].v.valU32;
    pCAPTUREFFTREPORTSParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_FFTREPORTSIZE, (A_UINT32)(((A_UINT32)&(pCAPTUREFFTREPORTSParms->fftreportsize)) - (A_UINT32)pCAPTUREFFTREPORTSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OFFSET, (A_UINT32)(((A_UINT32)&(pCAPTUREFFTREPORTSParms->offset)) - (A_UINT32)pCAPTUREFFTREPORTSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SIZE, (A_UINT32)(((A_UINT32)&(pCAPTUREFFTREPORTSParms->size)) - (A_UINT32)pCAPTUREFFTREPORTSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pCAPTUREFFTREPORTSParms->phyId)) - (A_UINT32)pCAPTUREFFTREPORTSParms), pParmsOffset);
    return((void*) pCAPTUREFFTREPORTSParms);
}

static CAPTUREFFTREPORTS_OP_FUNC CAPTUREFFTREPORTSOpFunc = NULL;

TLV2_API void registerCAPTUREFFTREPORTSHandler(CAPTUREFFTREPORTS_OP_FUNC fp)
{
    CAPTUREFFTREPORTSOpFunc = fp;
}

A_BOOL CAPTUREFFTREPORTSOp(void *pParms)
{
    CMD_CAPTUREFFTREPORTS_PARMS *pCAPTUREFFTREPORTSParms = (CMD_CAPTUREFFTREPORTS_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("CAPTUREFFTREPORTSOp: fftreportsize %u\n", pCAPTUREFFTREPORTSParms->fftreportsize);
    A_PRINTF("CAPTUREFFTREPORTSOp: offset %u\n", pCAPTUREFFTREPORTSParms->offset);
    A_PRINTF("CAPTUREFFTREPORTSOp: size %u\n", pCAPTUREFFTREPORTSParms->size);
    A_PRINTF("CAPTUREFFTREPORTSOp: phyId %u\n", pCAPTUREFFTREPORTSParms->phyId);
#endif //_DEBUG

    if (NULL != CAPTUREFFTREPORTSOpFunc) {
        (*CAPTUREFFTREPORTSOpFunc)(pCAPTUREFFTREPORTSParms);
    }
    return(TRUE);
}

void* initCAPTUREFFTREPORTSRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_CAPTUREFFTREPORTSRSP_PARMS  *pCAPTUREFFTREPORTSRSPParms = (CMD_CAPTUREFFTREPORTSRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pCAPTUREFFTREPORTSRSPParms->fftStatus = pParmDict[PARM_FFTSTATUS].v.valU32;
    pCAPTUREFFTREPORTSRSPParms->offset = pParmDict[PARM_OFFSET].v.valU32;
    pCAPTUREFFTREPORTSRSPParms->size = pParmDict[PARM_SIZE].v.valU32;
    memset(pCAPTUREFFTREPORTSRSPParms->data4k, 0, sizeof(pCAPTUREFFTREPORTSRSPParms->data4k));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_FFTSTATUS, (A_UINT32)(((A_UINT32)&(pCAPTUREFFTREPORTSRSPParms->fftStatus)) - (A_UINT32)pCAPTUREFFTREPORTSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OFFSET, (A_UINT32)(((A_UINT32)&(pCAPTUREFFTREPORTSRSPParms->offset)) - (A_UINT32)pCAPTUREFFTREPORTSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SIZE, (A_UINT32)(((A_UINT32)&(pCAPTUREFFTREPORTSRSPParms->size)) - (A_UINT32)pCAPTUREFFTREPORTSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DATA4K, (A_UINT32)(((A_UINT32)&(pCAPTUREFFTREPORTSRSPParms->data4k)) - (A_UINT32)pCAPTUREFFTREPORTSRSPParms), pParmsOffset);
    return((void*) pCAPTUREFFTREPORTSRSPParms);
}

static CAPTUREFFTREPORTSRSP_OP_FUNC CAPTUREFFTREPORTSRSPOpFunc = NULL;

TLV2_API void registerCAPTUREFFTREPORTSRSPHandler(CAPTUREFFTREPORTSRSP_OP_FUNC fp)
{
    CAPTUREFFTREPORTSRSPOpFunc = fp;
}

A_BOOL CAPTUREFFTREPORTSRSPOp(void *pParms)
{
    CMD_CAPTUREFFTREPORTSRSP_PARMS *pCAPTUREFFTREPORTSRSPParms = (CMD_CAPTUREFFTREPORTSRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("CAPTUREFFTREPORTSRSPOp: fftStatus %u\n", pCAPTUREFFTREPORTSRSPParms->fftStatus);
    A_PRINTF("CAPTUREFFTREPORTSRSPOp: offset %u\n", pCAPTUREFFTREPORTSRSPParms->offset);
    A_PRINTF("CAPTUREFFTREPORTSRSPOp: size %u\n", pCAPTUREFFTREPORTSRSPParms->size);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 4096 entries
    {
        A_PRINTF("CAPTUREFFTREPORTSRSPOp: data4k 0x%x\n", pCAPTUREFFTREPORTSRSPParms->data4k[i]);
    }
#endif //_DEBUG

    if (NULL != CAPTUREFFTREPORTSRSPOpFunc) {
        (*CAPTUREFFTREPORTSRSPOpFunc)(pCAPTUREFFTREPORTSRSPParms);
    }
    return(TRUE);
}
