/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdEepromWrite.s
#ifndef _CMDEEPROMWRITE_H_
#define _CMDEEPROMWRITE_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct eepromwrite_parms {
    A_UINT32	offset;
    A_UINT32	size;
    A_UINT8	data4k[4096];
} __ATTRIB_PACK CMD_EEPROMWRITE_PARMS;

typedef void (*EEPROMWRITE_OP_FUNC)(void *pParms);

// Exposed functions

void* initEEPROMWRITEOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL EEPROMWRITEOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDEEPROMWRITE_H_
