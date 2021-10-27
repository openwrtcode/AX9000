/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdLowPower.s
#include "tlv2Inc.h"
#include "cmdLowPower.h"

void* initLOWPOWEROpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_LOWPOWER_PARMS  *pLOWPOWERParms = (CMD_LOWPOWER_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pLOWPOWERParms->lowPowerMode = pParmDict[PARM_LOWPOWERMODE].v.valU8;
    pLOWPOWERParms->phyIdMask = pParmDict[PARM_PHYIDMASK].v.valU8;
    pLOWPOWERParms->lowPowerFeatureMask = pParmDict[PARM_LOWPOWERFEATUREMASK].v.valU32;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_LOWPOWERMODE, (A_UINT32)(((A_UINT32)&(pLOWPOWERParms->lowPowerMode)) - (A_UINT32)pLOWPOWERParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PHYIDMASK, (A_UINT32)(((A_UINT32)&(pLOWPOWERParms->phyIdMask)) - (A_UINT32)pLOWPOWERParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LOWPOWERFEATUREMASK, (A_UINT32)(((A_UINT32)&(pLOWPOWERParms->lowPowerFeatureMask)) - (A_UINT32)pLOWPOWERParms), pParmsOffset);
    return((void*) pLOWPOWERParms);
}

static LOWPOWER_OP_FUNC LOWPOWEROpFunc = NULL;

TLV2_API void registerLOWPOWERHandler(LOWPOWER_OP_FUNC fp)
{
    LOWPOWEROpFunc = fp;
}

A_BOOL LOWPOWEROp(void *pParms)
{
    CMD_LOWPOWER_PARMS *pLOWPOWERParms = (CMD_LOWPOWER_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("LOWPOWEROp: lowPowerMode %u\n", pLOWPOWERParms->lowPowerMode);
    A_PRINTF("LOWPOWEROp: phyIdMask %u\n", pLOWPOWERParms->phyIdMask);
    A_PRINTF("LOWPOWEROp: lowPowerFeatureMask 0x%x\n", pLOWPOWERParms->lowPowerFeatureMask);
#endif //_DEBUG

    if (NULL != LOWPOWEROpFunc) {
        (*LOWPOWEROpFunc)(pLOWPOWERParms);
    }
    return(TRUE);
}
