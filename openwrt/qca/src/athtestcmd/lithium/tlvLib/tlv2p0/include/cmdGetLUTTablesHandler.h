/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdGetLUTTablesHandler.s
#ifndef _CMDGETLUTTABLESHANDLER_H_
#define _CMDGETLUTTABLESHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct getluttables_parms {
    A_UINT8	LUTdumpOption;
    A_UINT8	phyId;
    A_UINT16	chainMask;
} __ATTRIB_PACK CMD_GETLUTTABLES_PARMS;

typedef struct getluttablesrsp_parms {
    A_UINT8	data4k[4096];
    A_UINT8	status;
    A_UINT8	phyId;
    A_UINT16	rspDataLen;
} __ATTRIB_PACK CMD_GETLUTTABLESRSP_PARMS;

typedef void (*GETLUTTABLES_OP_FUNC)(void *pParms);
typedef void (*GETLUTTABLESRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initGETLUTTABLESOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GETLUTTABLESOp(void *pParms);

void* initGETLUTTABLESRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL GETLUTTABLESRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDGETLUTTABLESHANDLER_H_
