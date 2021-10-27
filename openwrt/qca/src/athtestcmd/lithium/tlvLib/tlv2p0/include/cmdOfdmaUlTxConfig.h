/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdOfdmaUlTxConfig.s
#ifndef _CMDOFDMAULTXCONFIG_H_
#define _CMDOFDMAULTXCONFIG_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct ofdmaultxconfigrsp_parms {
    A_UINT8	preFECPad;
    A_UINT8	ldpcExtraSymbol;
    A_UINT8	peDisambiguity;
    A_UINT8	packetExt;
    A_UINT32	numOfHeLtf;
} __ATTRIB_PACK CMD_OFDMAULTXCONFIGRSP_PARMS;

typedef void (*OFDMAULTXCONFIG_OP_FUNC)(void *pParms);
typedef void (*OFDMAULTXCONFIGRSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initOFDMAULTXCONFIGOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL OFDMAULTXCONFIGOp(void *pParms);

void* initOFDMAULTXCONFIGRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL OFDMAULTXCONFIGRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDOFDMAULTXCONFIG_H_
