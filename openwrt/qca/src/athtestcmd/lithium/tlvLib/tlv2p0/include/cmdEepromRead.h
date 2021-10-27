/* Copyright (c) 2018-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdEepromRead.s
#ifndef _CMDEEPROMREAD_H_
#define _CMDEEPROMREAD_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct eepromread_parms {
    A_UINT32	eepromCalDataSize;
    A_UINT32	offset;
    A_UINT32	size;
} __ATTRIB_PACK CMD_EEPROMREAD_PARMS;

typedef struct eepromreadrsp_parms {
    A_UINT8	status;
    A_UINT8	pad3[3];
    A_UINT32	offset;
    A_UINT32	size;
    A_UINT8	data4k[4096];
} __ATTRIB_PACK CMD_EEPROMREADRSP_PARMS;

typedef void (*EEPROMREAD_OP_FUNC)(void *pParms);
typedef void (*EEPROMREADRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initEEPROMREADOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL EEPROMREADOp(void *pParms);

void* initEEPROMREADRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL EEPROMREADRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDEEPROMREAD_H_
