/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdSetPerChainPwrHandler.s
#ifndef _CMDSETPERCHAINPWRHANDLER_H_
#define _CMDSETPERCHAINPWRHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct setperchainpwr_parms {
    A_UINT8	phyId;
    A_UINT8	pad1;
    A_UINT16	chainMask;
    A_INT8	powerValPerChain[8];
} __ATTRIB_PACK CMD_SETPERCHAINPWR_PARMS;

typedef struct setperchainpwrrsp_parms {
    A_UINT8	status;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_SETPERCHAINPWRRSP_PARMS;

typedef void (*SETPERCHAINPWR_OP_FUNC)(void *pParms);
typedef void (*SETPERCHAINPWRRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initSETPERCHAINPWROpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL SETPERCHAINPWROp(void *pParms);

void* initSETPERCHAINPWRRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL SETPERCHAINPWRRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDSETPERCHAINPWRHANDLER_H_
