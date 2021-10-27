/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdConfigureSpectralScan.s
#ifndef _CMDCONFIGURESPECTRALSCAN_H_
#define _CMDCONFIGURESPECTRALSCAN_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct configurespectralscan_parms {
    A_UINT16	freq;
    A_UINT16	freq2;
    A_UINT16	chainMask;
    A_UINT8	bandwidth;
    A_UINT8	ScanCount;
    A_UINT8	ScanPeriod;
    A_UINT8	ScanPriority;
    A_UINT8	ScanFFTSize;
    A_UINT8	ScanGCEna;
    A_UINT8	ScanRestartEna;
    A_UINT8	ScanInitDelay;
    A_UINT8	ScanNBToneThr;
    A_UINT8	ScanStrBinThr;
    A_UINT8	ScanWBRptMode;
    A_UINT8	ScanRssiRptMode;
    A_UINT8	ScanPwrFormat;
    A_UINT8	ScanRptMode;
    A_UINT8	ScanBinScale;
    A_UINT8	ScandBmAdj;
    A_UINT8	ScanChnMask;
    A_UINT8	phyId;
    A_INT32	ScanRssiThr;
    A_INT32	ScanNoiseFloorRef;
} __ATTRIB_PACK CMD_CONFIGURESPECTRALSCAN_PARMS;

typedef struct configurespectralscanrsp_parms {
    A_UINT32	fftreportsize;
} __ATTRIB_PACK CMD_CONFIGURESPECTRALSCANRSP_PARMS;

typedef void (*CONFIGURESPECTRALSCAN_OP_FUNC)(void *pParms);
typedef void (*CONFIGURESPECTRALSCANRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initCONFIGURESPECTRALSCANOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL CONFIGURESPECTRALSCANOp(void *pParms);

void* initCONFIGURESPECTRALSCANRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL CONFIGURESPECTRALSCANRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDCONFIGURESPECTRALSCAN_H_
