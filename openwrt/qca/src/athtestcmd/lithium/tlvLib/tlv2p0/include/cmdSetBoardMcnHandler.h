/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdSetBoardMcnHandler.s
#ifndef _CMDSETBOARDMCNHANDLER_H_
#define _CMDSETBOARDMCNHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct setboardmcn_parms {
    A_UINT8	phyId;
    A_UINT8	boardMcn[20];
    A_UINT8	pad3[3];
} __ATTRIB_PACK CMD_SETBOARDMCN_PARMS;

typedef struct setboardmcnrsp_parms {
    A_UINT32	status;
} __ATTRIB_PACK CMD_SETBOARDMCNRSP_PARMS;

typedef void (*SETBOARDMCN_OP_FUNC)(void *pParms);
typedef void (*SETBOARDMCNRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initSETBOARDMCNOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL SETBOARDMCNOp(void *pParms);

void* initSETBOARDMCNRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL SETBOARDMCNRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDSETBOARDMCNHANDLER_H_
