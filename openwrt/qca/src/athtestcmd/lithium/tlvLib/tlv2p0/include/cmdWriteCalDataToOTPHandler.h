/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdWriteCalDataToOTPHandler.s
#ifndef _CMDWRITECALDATATOOTPHANDLER_H_
#define _CMDWRITECALDATATOOTPHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct writecaldatatootp_parms {
    A_UINT8	phyID;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_WRITECALDATATOOTP_PARMS;

typedef struct writecaldatatootprsp_parms {
    A_UINT8	status;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_WRITECALDATATOOTPRSP_PARMS;

typedef void (*WRITECALDATATOOTP_OP_FUNC)(void *pParms);
typedef void (*WRITECALDATATOOTPRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initWRITECALDATATOOTPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL WRITECALDATATOOTPOp(void *pParms);

void* initWRITECALDATATOOTPRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL WRITECALDATATOOTPRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDWRITECALDATATOOTPHANDLER_H_
