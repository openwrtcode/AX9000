/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdRadarDetectHandler.s
#ifndef _CMDRADARDETECTHANDLER_H_
#define _CMDRADARDETECTHANDLER_H_

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#if defined(WIN32) || defined(WIN64)
#pragma pack (push, 1)
#endif // WIN32 || WIN64

typedef struct radardetect_parms {
    A_UINT16 freq;
    A_UINT16 freq2;
    A_UINT16 regDmn[2];
    A_UINT16 duration;
    A_UINT8  phyId;
    A_UINT8  bandwidth;
} __ATTRIB_PACK CMD_RADARDETECT_PARMS;

typedef struct radardetectrsp_parms {
    A_UINT32 numRadarEvents;
} __ATTRIB_PACK CMD_RADARDETECTRSP_PARMS;

typedef void (*RADARDETECT_OP_FUNC)(void *pParms);
typedef void (*RADARDETECTRSP_OP_FUNC)(void *pParms);

// Exposed functions

void *initRADARDETECTOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RADARDETECTOp(void *pParms);

void *initRADARDETECTRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
A_BOOL RADARDETECTRSPOp(void *pParms);

#if defined(WIN32) || defined(WIN64)
#pragma pack(pop)
#endif // WIN32 || WIN64

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif // _CMDRADARDETECTHANDLER_H_
