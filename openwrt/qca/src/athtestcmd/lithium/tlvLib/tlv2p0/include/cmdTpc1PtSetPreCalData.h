/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdTpc1PtSetPreCalData.s
#ifndef _CMDTPC1PTSETPRECALDATA_H_
#define _CMDTPC1PTSETPRECALDATA_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct tpc1ptsetprecaldata_parms {
    A_UINT8	phyId;
    A_UINT8	calOffsetPower;
    A_UINT8	overrideEnable;
    A_UINT8	band;
    A_UINT16	TpcFreq[8];
} __ATTRIB_PACK CMD_TPC1PTSETPRECALDATA_PARMS;

typedef struct tpc1ptsetprecaldatarsp_parms {
    A_UINT8	status;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_TPC1PTSETPRECALDATARSP_PARMS;

typedef void (*TPC1PTSETPRECALDATA_OP_FUNC)(void *pParms);
typedef void (*TPC1PTSETPRECALDATARSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initTPC1PTSETPRECALDATAOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPC1PTSETPRECALDATAOp(void *pParms);

void* initTPC1PTSETPRECALDATARSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPC1PTSETPRECALDATARSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDTPC1PTSETPRECALDATA_H_
