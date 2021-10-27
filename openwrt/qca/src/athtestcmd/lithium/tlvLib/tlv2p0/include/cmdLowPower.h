/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdLowPower.s
#ifndef _CMDLOWPOWER_H_
#define _CMDLOWPOWER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct lowpower_parms {
    A_UINT8	lowPowerMode;
    A_UINT8	phyIdMask;
    A_UINT32	lowPowerFeatureMask;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_LOWPOWER_PARMS;

typedef void (*LOWPOWER_OP_FUNC)(void *pParms);

// Exposed functions

void* initLOWPOWEROpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL LOWPOWEROp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDLOWPOWER_H_
