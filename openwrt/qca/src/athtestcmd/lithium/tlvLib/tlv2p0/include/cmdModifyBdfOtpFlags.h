/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdModifyBDFOTPflags.s
#ifndef _CMDMODIFYBDFOTPFLAGS_H_
#define _CMDMODIFYBDFOTPFLAGS_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct modifybdfotpflags_parms {
    A_UINT8	modifyBdfOtpFlags;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_MODIFYBDFOTPFLAGS_PARMS;

typedef void (*MODIFYBDFOTPFLAGS_OP_FUNC)(void *pParms);

// Exposed functions

void* initMODIFYBDFOTPFLAGSOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL MODIFYBDFOTPFLAGSOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDMODIFYBDFOTPFLAGS_H_
