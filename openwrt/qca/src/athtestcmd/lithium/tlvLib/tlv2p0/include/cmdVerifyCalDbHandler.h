/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdVerifyCalDbHandler.s
#ifndef _CMDVERIFYCALDBHANDLER_H_
#define _CMDVERIFYCALDBHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct verifycaldb_parms {
    A_UINT8	phyId;
    A_UINT8	calType;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_VERIFYCALDB_PARMS;

typedef struct verifycaldbrsp_parms {
    A_UINT8	phyId;
    A_UINT8	status;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_VERIFYCALDBRSP_PARMS;

typedef void (*VERIFYCALDB_OP_FUNC)(void *pParms);
typedef void (*VERIFYCALDBRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initVERIFYCALDBOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL VERIFYCALDBOp(void *pParms);

void* initVERIFYCALDBRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL VERIFYCALDBRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDVERIFYCALDBHANDLER_H_
