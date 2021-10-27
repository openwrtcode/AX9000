/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdCalDbSaveToHostHandler.s
#ifndef _CMDCALDBSAVETOHOSTHANDLER_H_
#define _CMDCALDBSAVETOHOSTHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct caldbsavetohost_parms {
    A_UINT8	phyId;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_CALDBSAVETOHOST_PARMS;

typedef struct caldbsavetohostrsp_parms {
    A_UINT8	phyId;
    A_UINT8	status;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_CALDBSAVETOHOSTRSP_PARMS;

typedef void (*CALDBSAVETOHOST_OP_FUNC)(void *pParms);
typedef void (*CALDBSAVETOHOSTRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initCALDBSAVETOHOSTOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL CALDBSAVETOHOSTOp(void *pParms);

void* initCALDBSAVETOHOSTRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL CALDBSAVETOHOSTRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDCALDBSAVETOHOSTHANDLER_H_
