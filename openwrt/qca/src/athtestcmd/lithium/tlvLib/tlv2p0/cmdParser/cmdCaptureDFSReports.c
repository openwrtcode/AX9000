/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdCaptureDFSReports.s
#include "tlv2Inc.h"
#include "cmdCaptureDFSReports.h"

void *initCAPTUREDFSREPORTSOpParms(
        A_UINT8 *pParmsCommon,
        PARM_OFFSET_TBL *pParmsOffset,
        PARM_DICT *pParmDict)
{
    int i, j; // for initializing array parameter
    CMD_CAPTUREDFSREPORTS_PARMS *pCAPTUREDFSREPORTSParms = (CMD_CAPTUREDFSREPORTS_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) {
        return NULL;
    }
    i = j = 0; // assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pCAPTUREDFSREPORTSParms->offset         = pParmDict[PARM_OFFSET].v.valU32;
    pCAPTUREDFSREPORTSParms->numRadarEvents = pParmDict[PARM_NUMRADAREVENTS].v.valU32;
    pCAPTUREDFSREPORTSParms->phyId          = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_OFFSET,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSParms->offset)) - (A_UINT32)pCAPTUREDFSREPORTSParms),
            pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMRADAREVENTS,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSParms->numRadarEvents)) - (A_UINT32)pCAPTUREDFSREPORTSParms),
            pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYID,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSParms->phyId)) - (A_UINT32)pCAPTUREDFSREPORTSParms),
            pParmsOffset);
    return (void *)pCAPTUREDFSREPORTSParms;
}

static CAPTUREDFSREPORTS_OP_FUNC CAPTUREDFSREPORTSOpFunc = NULL;

TLV2_API void registerCAPTUREDFSREPORTSHandler(CAPTUREDFSREPORTS_OP_FUNC fp)
{
    CAPTUREDFSREPORTSOpFunc = fp;
}

A_BOOL CAPTUREDFSREPORTSOp(void *pParms)
{
    CMD_CAPTUREDFSREPORTS_PARMS *pCAPTUREDFSREPORTSParms = (CMD_CAPTUREDFSREPORTS_PARMS *)pParms;

#if 0 // for debugging, comment out this line, and uncomment the line below
// #ifdef _DEBUG
    int i; // for initializing array parameter
    i = 0; // assign a number to avoid warning in case i is not used

    A_PRINTF("CAPTUREDFSREPORTSOp: offset %u\n",         pCAPTUREDFSREPORTSParms->offset);
    A_PRINTF("CAPTUREDFSREPORTSOp: numRadarEvents %u\n", pCAPTUREDFSREPORTSParms->numRadarEvents);
    A_PRINTF("CAPTUREDFSREPORTSOp: phyId %u\n",          pCAPTUREDFSREPORTSParms->phyId);
#endif // _DEBUG

    if (NULL != CAPTUREDFSREPORTSOpFunc) {
        (*CAPTUREDFSREPORTSOpFunc)(pCAPTUREDFSREPORTSParms);
    }
    return TRUE;
}

void *initCAPTUREDFSREPORTSRSPOpParms(
        A_UINT8 *pParmsCommon,
        PARM_OFFSET_TBL *pParmsOffset,
        PARM_DICT *pParmDict)
{
    int i, j; // for initializing array parameter
    CMD_CAPTUREDFSREPORTSRSP_PARMS *pCAPTUREDFSREPORTSRSPParms = (CMD_CAPTUREDFSREPORTSRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) {
        return NULL;
    }
    i = j = 0; // assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pCAPTUREDFSREPORTSRSPParms->dfsStatus         = pParmDict[PARM_DFSSTATUS].v.valU32;
    pCAPTUREDFSREPORTSRSPParms->detection_mode[0] = 0;
    memset(&pCAPTUREDFSREPORTSRSPParms->detection_mode[1], 0, 999);
    pCAPTUREDFSREPORTSRSPParms->chan_freq[0] = 0;
    memset(&pCAPTUREDFSREPORTSRSPParms->chan_freq[1],      0, 999);
    pCAPTUREDFSREPORTSRSPParms->radar_freq[0] = 0;
    memset(&pCAPTUREDFSREPORTSRSPParms->radar_freq[1],     0, 999);
    pCAPTUREDFSREPORTSRSPParms->chan_width[0] = 0;
    memset(&pCAPTUREDFSREPORTSRSPParms->chan_width[1],     0, 999);
    pCAPTUREDFSREPORTSRSPParms->detector_id[0] = 0;
    memset(&pCAPTUREDFSREPORTSRSPParms->detector_id[1],    0, 999);
    pCAPTUREDFSREPORTSRSPParms->timestamp[0] = 0;
    memset(&pCAPTUREDFSREPORTSRSPParms->timestamp[1],      0, 999);
    pCAPTUREDFSREPORTSRSPParms->segment_id[0] = 0;
    memset(&pCAPTUREDFSREPORTSRSPParms->segment_id[1],     0, 999);
    pCAPTUREDFSREPORTSRSPParms->is_chirp[0] = 0;
    memset(&pCAPTUREDFSREPORTSRSPParms->is_chirp[1],       0, 999);
    pCAPTUREDFSREPORTSRSPParms->freq_offset[0] = 0;
    memset(&pCAPTUREDFSREPORTSRSPParms->freq_offset[1],    0, 999);
    pCAPTUREDFSREPORTSRSPParms->sidx[0] = 0;
    memset(&pCAPTUREDFSREPORTSRSPParms->sidx[1],           0, 999);

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_DFSSTATUS,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSRSPParms->dfsStatus)) - (A_UINT32)pCAPTUREDFSREPORTSRSPParms),
            pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DETECTION_MODE,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSRSPParms->detection_mode)) - (A_UINT32)pCAPTUREDFSREPORTSRSPParms),
            pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAN_FREQ,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSRSPParms->chan_freq)) - (A_UINT32)pCAPTUREDFSREPORTSRSPParms),
            pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RADAR_FREQ,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSRSPParms->radar_freq)) - (A_UINT32)pCAPTUREDFSREPORTSRSPParms),
            pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAN_WIDTH,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSRSPParms->chan_width)) - (A_UINT32)pCAPTUREDFSREPORTSRSPParms),
            pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DETECTOR_ID,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSRSPParms->detector_id)) - (A_UINT32)pCAPTUREDFSREPORTSRSPParms),
            pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TIMESTAMP,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSRSPParms->timestamp)) - (A_UINT32)pCAPTUREDFSREPORTSRSPParms),
            pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SEGMENT_ID,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSRSPParms->segment_id)) - (A_UINT32)pCAPTUREDFSREPORTSRSPParms),
            pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_IS_CHIRP,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSRSPParms->is_chirp)) - (A_UINT32)pCAPTUREDFSREPORTSRSPParms),
            pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FREQ_OFFSET,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSRSPParms->freq_offset)) - (A_UINT32)pCAPTUREDFSREPORTSRSPParms),
            pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SIDX,
            (A_UINT32)(((A_UINT32)&(pCAPTUREDFSREPORTSRSPParms->sidx)) - (A_UINT32)pCAPTUREDFSREPORTSRSPParms),
            pParmsOffset);
    return (void *)pCAPTUREDFSREPORTSRSPParms;
}

static CAPTUREDFSREPORTSRSP_OP_FUNC CAPTUREDFSREPORTSRSPOpFunc = NULL;

TLV2_API void registerCAPTUREDFSREPORTSRSPHandler(CAPTUREDFSREPORTSRSP_OP_FUNC fp)
{
    CAPTUREDFSREPORTSRSPOpFunc = fp;
}

A_BOOL CAPTUREDFSREPORTSRSPOp(void *pParms)
{
    CMD_CAPTUREDFSREPORTSRSP_PARMS *pCAPTUREDFSREPORTSRSPParms = (CMD_CAPTUREDFSREPORTSRSP_PARMS *)pParms;

#if 0 // for debugging, comment out this line, and uncomment the line below
// #ifdef _DEBUG
    int i; // for initializing array parameter
    i = 0; // assign a number to avoid warning in case i is not used

    A_PRINTF("CAPTUREDFSREPORTSRSPOp: dfsStatus %u\n", pCAPTUREDFSREPORTSRSPParms->dfsStatus);

    for (i = 0; i < 8; i++) { // can be modified to print up to 1000 entries
        A_PRINTF("CAPTUREDFSREPORTSRSPOp: detection_mode %u\n", pCAPTUREDFSREPORTSRSPParms->detection_mode[i]);
    }

    for (i = 0; i < 8; i++) { // can be modified to print up to 1000 entries
        A_PRINTF("CAPTUREDFSREPORTSRSPOp: chan_freq %u\n", pCAPTUREDFSREPORTSRSPParms->chan_freq[i]);
    }

    for (i = 0; i < 8; i++) { // can be modified to print up to 1000 entries
        A_PRINTF("CAPTUREDFSREPORTSRSPOp: radar_freq %u\n", pCAPTUREDFSREPORTSRSPParms->radar_freq[i]);
    }

    for (i = 0; i < 8; i++) { // can be modified to print up to 1000 entries
        A_PRINTF("CAPTUREDFSREPORTSRSPOp: chan_width %u\n", pCAPTUREDFSREPORTSRSPParms->chan_width[i]);
    }

    for (i = 0; i < 8; i++) { // can be modified to print up to 1000 entries
        A_PRINTF("CAPTUREDFSREPORTSRSPOp: detector_id %u\n", pCAPTUREDFSREPORTSRSPParms->detector_id[i]);
    }

    for (i = 0; i < 8; i++) { // can be modified to print up to 1000 entries
        A_PRINTF("CAPTUREDFSREPORTSRSPOp: timestamp %u\n", pCAPTUREDFSREPORTSRSPParms->timestamp[i]);
    }

    for (i = 0; i < 8; i++) { // can be modified to print up to 1000 entries
        A_PRINTF("CAPTUREDFSREPORTSRSPOp: segment_id %u\n", pCAPTUREDFSREPORTSRSPParms->segment_id[i]);
    }

    for (i = 0; i < 8; i++) { // can be modified to print up to 1000 entries
        A_PRINTF("CAPTUREDFSREPORTSRSPOp: is_chirp %u\n", pCAPTUREDFSREPORTSRSPParms->is_chirp[i]);
    }

    for (i = 0; i < 8; i++) { // can be modified to print up to 1000 entries
        A_PRINTF("CAPTUREDFSREPORTSRSPOp: freq_offset %d\n", pCAPTUREDFSREPORTSRSPParms->freq_offset[i]);
    }

    for (i = 0; i < 8; i++) { // can be modified to print up to 1000 entries
        A_PRINTF("CAPTUREDFSREPORTSRSPOp: sidx %d\n", pCAPTUREDFSREPORTSRSPParms->sidx[i]);
    }
#endif // _DEBUG

    if (NULL != CAPTUREDFSREPORTSRSPOpFunc) {
        (*CAPTUREDFSREPORTSRSPOpFunc)(pCAPTUREDFSREPORTSRSPParms);
    }
    return TRUE;
}
