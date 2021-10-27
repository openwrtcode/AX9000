/* Copyright (c) 2018-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdEepromGetSize.s
#ifndef _CMDEEPROMGETSIZE_H_
#define _CMDEEPROMGETSIZE_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct eepromgetsizersp_parms {
    A_UINT8	status;
    A_UINT8	pad3[3];
    A_UINT32	eepromCalDataSize;
} __ATTRIB_PACK CMD_EEPROMGETSIZERSP_PARMS;

typedef void (*EEPROMGETSIZE_OP_FUNC)(void *pParms);
typedef void (*EEPROMGETSIZERSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initEEPROMGETSIZEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL EEPROMGETSIZEOp(void *pParms);

void* initEEPROMGETSIZERSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL EEPROMGETSIZERSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDEEPROMGETSIZE_H_
