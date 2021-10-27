/* Copyright (c) 2017-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from ./input\cmdNoiseFloorCalSave.s
#ifndef _CMDNOISEFLOORCALSAVE_H_
#define _CMDNOISEFLOORCALSAVE_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

#ifndef TLV2_MAX_CHAIN
#define TLV2_MAX_CHAIN          16
#endif
#define FTM_NF_CAL_FREQ_NUM     16
#define FTM_NF_CAL_VALUE_NUM    (FTM_NF_CAL_FREQ_NUM * TLV2_MAX_CHAIN)

typedef struct noisefloorcalsave_parms {
    A_UINT16	freqs[FTM_NF_CAL_FREQ_NUM];
    A_UINT32	NFCalValues[FTM_NF_CAL_VALUE_NUM];
    A_UINT16	itemNum;
    A_UINT8	phyId;
    A_UINT8	pad[1];
} __ATTRIB_PACK CMD_NOISEFLOORCALSAVE_PARMS;

typedef struct noisefloorcalsaversp_parms {
    A_UINT32	status;
    A_UINT8	phyId;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_NOISEFLOORCALSAVERSP_PARMS;

typedef void (*NOISEFLOORCALSAVE_OP_FUNC)(void *pParms);
typedef void (*NOISEFLOORCALSAVERSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initNOISEFLOORCALSAVEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL NOISEFLOORCALSAVEOp(void *pParms);

void* initNOISEFLOORCALSAVERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL NOISEFLOORCALSAVERSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDNOISEFLOORCALSAVE_H_
