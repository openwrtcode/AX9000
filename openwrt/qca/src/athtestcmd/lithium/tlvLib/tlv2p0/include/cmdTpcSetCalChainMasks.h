/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdTpcSetCalChainMasks.s
#ifndef _CMDTPCSETCALCHAINMASKS_H_
#define _CMDTPCSETCALCHAINMASKS_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct tpcsetcalchainmasks_parms {
    A_UINT8	phyId;
    A_UINT8	pad1;
    A_UINT16	txMask2G;
    A_UINT16	rxMask2G;
    A_UINT16	txMask5G;
    A_UINT16	rxMask5G;
    A_UINT32	concurrencyModeMask;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_TPCSETCALCHAINMASKS_PARMS;

typedef struct tpcsetcalchainmasksrsp_parms {
    A_UINT8	status;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_TPCSETCALCHAINMASKSRSP_PARMS;

typedef void (*TPCSETCALCHAINMASKS_OP_FUNC)(void *pParms);
typedef void (*TPCSETCALCHAINMASKSRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initTPCSETCALCHAINMASKSOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPCSETCALCHAINMASKSOp(void *pParms);

void* initTPCSETCALCHAINMASKSRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPCSETCALCHAINMASKSRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDTPCSETCALCHAINMASKS_H_
