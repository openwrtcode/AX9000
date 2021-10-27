/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdTpcFullPtSetPreCalData.s
#ifndef _CMDTPCFULLPTSETPRECALDATA_H_
#define _CMDTPCFULLPTSETPRECALDATA_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct tpcfullptsetprecaldata_parms {
    A_UINT8	phyId;
    A_UINT8	overrideEnable;
    A_UINT8	band;
    A_UINT8	pad1;
    A_UINT16	TpcFreqFullPt[32];
    A_UINT8	TpcCalDataTgtPwr[32];
    A_UINT8	TpcCalRfGain[32];
} __ATTRIB_PACK CMD_TPCFULLPTSETPRECALDATA_PARMS;

typedef struct tpcfullptsetprecaldatarsp_parms {
    A_UINT8	status;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_TPCFULLPTSETPRECALDATARSP_PARMS;

typedef void (*TPCFULLPTSETPRECALDATA_OP_FUNC)(void *pParms);
typedef void (*TPCFULLPTSETPRECALDATARSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initTPCFULLPTSETPRECALDATAOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPCFULLPTSETPRECALDATAOp(void *pParms);

void* initTPCFULLPTSETPRECALDATARSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPCFULLPTSETPRECALDATARSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDTPCFULLPTSETPRECALDATA_H_
