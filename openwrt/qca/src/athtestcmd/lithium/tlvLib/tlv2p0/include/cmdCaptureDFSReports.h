/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdCaptureDFSReports.s
#ifndef _CMDCAPTUREDFSREPORTS_H_
#define _CMDCAPTUREDFSREPORTS_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif // WIN32 || WIN64

typedef struct capturedfsreports_parms {
    A_UINT32 offset;
    A_UINT32 numRadarEvents;
    A_UINT8  phyId;
    A_UINT8  pad[3];
} __ATTRIB_PACK CMD_CAPTUREDFSREPORTS_PARMS;

typedef struct capturedfsreportsrsp_parms {
    A_UINT32 dfsStatus;
    A_UINT32 detection_mode[1000];
    A_UINT32 chan_freq[1000];
    A_UINT32 radar_freq[1000];
    A_UINT32 chan_width[1000];
    A_UINT32 detector_id[1000];
    A_UINT32 timestamp[1000];
    A_UINT32 segment_id[1000];
    A_UINT32 is_chirp[1000];
    A_INT32  freq_offset[1000];
    A_INT32  sidx[1000];
} __ATTRIB_PACK CMD_CAPTUREDFSREPORTSRSP_PARMS;

typedef void (*CAPTUREDFSREPORTS_OP_FUNC)(void *pParms);
typedef void (*CAPTUREDFSREPORTSRSP_OP_FUNC)(void *pParms);

// Exposed functions

void *initCAPTUREDFSREPORTSOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL CAPTUREDFSREPORTSOp(void *pParms);

void *initCAPTUREDFSREPORTSRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL CAPTUREDFSREPORTSRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif // WIN32 || WIN64

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif // _CMDCAPTUREDFSREPORTS_H_
