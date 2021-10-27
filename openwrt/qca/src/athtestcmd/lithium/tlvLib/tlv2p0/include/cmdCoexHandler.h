/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdCoexHandler.s
#ifndef _CMDCOEXHANDLER_H_
#define _CMDCOEXHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct coexreq_parms {
    A_UINT32	WlanCoexWeight[11];
    A_UINT16	shareChainMask;
    A_UINT8	enableDynamicAggr;
    A_UINT8	enableConcurrentTxChain0;
    A_UINT8	btRxAllowWlanTxUnshared;
    A_UINT8	btTxAllowWlanTxShared;
    A_UINT8	wlanTxAllowBtRxShared;
    A_UINT8	wlanRxAllowBtTxShared;
    A_UINT8	concurrentTxEnable;
    A_UINT8	btRxAllowWlanUnsharedTx;
    A_UINT8	wlan1sRxBtTx;
    A_UINT8	enableBtContInfo;
    A_UINT8	enableBtSchedInfo;
    A_UINT8	enableBtLnaInfo;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_COEXREQ_PARMS;

typedef struct coexreqrsp_parms {
    A_UINT8	status;
    A_UINT8	reason;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_COEXREQRSP_PARMS;

typedef void (*COEXREQ_OP_FUNC)(void *pParms);
typedef void (*COEXREQRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initCOEXREQOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL COEXREQOp(void *pParms);

void* initCOEXREQRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL COEXREQRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDCOEXHANDLER_H_
