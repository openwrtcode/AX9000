/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdInvalidateCalDataOTPHandler.s
#ifndef _CMDINVALIDATECALDATAOTPHANDLER_H_
#define _CMDINVALIDATECALDATAOTPHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct invalidatecaldataotp_parms {
    A_UINT8	phyId;
    A_UINT8	sectionId;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_INVALIDATECALDATAOTP_PARMS;

typedef struct invalidatecaldataotprsp_parms {
    A_UINT8	status;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_INVALIDATECALDATAOTPRSP_PARMS;

typedef void (*INVALIDATECALDATAOTP_OP_FUNC)(void *pParms);
typedef void (*INVALIDATECALDATAOTPRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initINVALIDATECALDATAOTPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL INVALIDATECALDATAOTPOp(void *pParms);

void* initINVALIDATECALDATAOTPRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL INVALIDATECALDATAOTPRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDINVALIDATECALDATAOTPHANDLER_H_
