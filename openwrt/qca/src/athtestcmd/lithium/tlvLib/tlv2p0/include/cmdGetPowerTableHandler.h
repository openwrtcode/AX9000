/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdGetPowerTableHandler.s
#ifndef _CMDGETPOWERTABLEHANDLER_H_
#define _CMDGETPOWERTABLEHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct getpowertable_parms {
    A_UINT8	phyId;
    A_UINT16	chainMask;
    A_UINT8	pad[1];
} __ATTRIB_PACK CMD_GETPOWERTABLE_PARMS;

typedef struct getpowertablersp_parms {
    A_UINT8	data4k[4096];
    A_UINT8	status;
    A_UINT8	phyId;
    A_UINT16	rspDataLen;
} __ATTRIB_PACK CMD_GETPOWERTABLERSP_PARMS;

typedef void (*GETPOWERTABLE_OP_FUNC)(void *pParms);
typedef void (*GETPOWERTABLERSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initGETPOWERTABLEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GETPOWERTABLEOp(void *pParms);

void* initGETPOWERTABLERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GETPOWERTABLERSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDGETPOWERTABLEHANDLER_H_
