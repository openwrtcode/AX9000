/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdCaptureFFTReports.s
#ifndef _CMDCAPTUREFFTREPORTS_H_
#define _CMDCAPTUREFFTREPORTS_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct capturefftreports_parms {
    A_UINT32	fftreportsize;
    A_UINT32	offset;
    A_UINT32	size;
    A_UINT8	phyId;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_CAPTUREFFTREPORTS_PARMS;

typedef struct capturefftreportsrsp_parms {
    A_UINT32	fftStatus;
    A_UINT32	offset;
    A_UINT32	size;
    A_UINT8	data4k[4096];
} __ATTRIB_PACK CMD_CAPTUREFFTREPORTSRSP_PARMS;

typedef void (*CAPTUREFFTREPORTS_OP_FUNC)(void *pParms);
typedef void (*CAPTUREFFTREPORTSRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initCAPTUREFFTREPORTSOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL CAPTUREFFTREPORTSOp(void *pParms);

void* initCAPTUREFFTREPORTSRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL CAPTUREFFTREPORTSRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDCAPTUREFFTREPORTS_H_
