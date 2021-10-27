/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdTpc1PtSetChanPwr.s
#ifndef _CMDTPC1PTSETCHANPWR_H_
#define _CMDTPC1PTSETCHANPWR_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct tpc1ptsetchanpwr_parms {
    A_UINT8	phyId;
    A_UINT8	chainIdx;
    A_UINT8	overrideEnable;
    A_UINT8	pad1;
    A_UINT16	TpcFreq[8];
    A_INT16	TpcPwr[8];
} __ATTRIB_PACK CMD_TPC1PTSETCHANPWR_PARMS;

typedef struct tpc1ptsetchanpwrrsp_parms {
    A_UINT8	status;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_TPC1PTSETCHANPWRRSP_PARMS;

typedef void (*TPC1PTSETCHANPWR_OP_FUNC)(void *pParms);
typedef void (*TPC1PTSETCHANPWRRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initTPC1PTSETCHANPWROpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPC1PTSETCHANPWROp(void *pParms);

void* initTPC1PTSETCHANPWRRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPC1PTSETCHANPWRRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDTPC1PTSETCHANPWR_H_
