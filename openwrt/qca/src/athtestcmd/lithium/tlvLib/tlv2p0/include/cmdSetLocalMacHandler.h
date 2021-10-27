/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdSetLocalMacHandler.s
#ifndef _CMDSETLOCALMACHANDLER_H_
#define _CMDSETLOCALMACHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct setlocalmac_parms {
    A_UINT8	phyId;
    A_UINT8	localMac[54];
    A_UINT8	pad1;
} __ATTRIB_PACK CMD_SETLOCALMAC_PARMS;

typedef struct setlocalmacrsp_parms {
    A_UINT32	status;
} __ATTRIB_PACK CMD_SETLOCALMACRSP_PARMS;

typedef void (*SETLOCALMAC_OP_FUNC)(void *pParms);
typedef void (*SETLOCALMACRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initSETLOCALMACOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL SETLOCALMACOp(void *pParms);

void* initSETLOCALMACRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL SETLOCALMACRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDSETLOCALMACHANDLER_H_
