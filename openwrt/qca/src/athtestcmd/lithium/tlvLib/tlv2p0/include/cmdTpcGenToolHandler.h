/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdTpcGenToolHandler.s
#ifndef _CMDTPCGENTOOLHANDLER_H_
#define _CMDTPCGENTOOLHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct tpcgentool_parms {
    A_UINT32	countryCode;
    A_UINT32	regDomain;
    A_INT32	ctl;
    A_INT8	sarIndex;
    A_UINT8	phyMode;
    A_UINT8	beamforming;
    A_UINT8	ctlrd;
    A_UINT16	freq;
    A_UINT8	chainIdx;
    A_UINT8	chainMask;
    A_UINT16	rate;
    A_UINT32	nss;
    A_UINT8	pad[2];
} __ATTRIB_PACK CMD_TPCGENTOOL_PARMS;

typedef struct tpcgentoolrsp_parms {
    A_UINT8	tpcPower;
    A_UINT8	RegDmnFW;
    A_UINT8	status;
    A_UINT8	pad[1];
} __ATTRIB_PACK CMD_TPCGENTOOLRSP_PARMS;

typedef void (*TPCGENTOOL_OP_FUNC)(void *pParms);
typedef void (*TPCGENTOOLRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initTPCGENTOOLOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPCGENTOOLOp(void *pParms);

void* initTPCGENTOOLRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL TPCGENTOOLRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDTPCGENTOOLHANDLER_H_
