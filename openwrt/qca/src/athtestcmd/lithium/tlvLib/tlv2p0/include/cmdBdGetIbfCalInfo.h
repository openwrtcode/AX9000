/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdBdGetIbfCalInfo.s
#ifndef _CMDBDGETIBFCALINFO_H_
#define _CMDBDGETIBFCALINFO_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif //WIN32 || WIN64

typedef struct bdgetibfcalinfo_parms {
    A_UINT8	phyId;
    A_UINT8	pad[3];
} __ATTRIB_PACK CMD_BDGETIBFCALINFO_PARMS;

typedef struct bdgetibfcalinforsp_parms {
    A_UINT8	status;
    A_UINT8	numFreq;
    A_UINT8	numChain;
    A_UINT8	pad1;
    A_UINT32	freqOffset;
    A_UINT32	ibfCalDataOffset;
} __ATTRIB_PACK CMD_BDGETIBFCALINFORSP_PARMS;

typedef void (*BDGETIBFCALINFO_OP_FUNC)(void *pParms);
typedef void (*BDGETIBFCALINFORSP_OP_FUNC)(void *pParms);

// Exposed functions

void* initBDGETIBFCALINFOOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL BDGETIBFCALINFOOp(void *pParms);

void* initBDGETIBFCALINFORSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL BDGETIBFCALINFORSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif //WIN32 || WIN64


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif //_CMDBDGETIBFCALINFO_H_
