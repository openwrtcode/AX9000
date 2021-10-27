/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input\cmdWriteCalDataToOTPHandler.s
#include "tlv2Inc.h"
#include "cmdWriteCalDataToOTPHandler.h"

void* initWRITECALDATATOOTPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_WRITECALDATATOOTP_PARMS  *pWRITECALDATATOOTPParms = (CMD_WRITECALDATATOOTP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pWRITECALDATATOOTPParms->phyID = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pWRITECALDATATOOTPParms->phyID)) - (A_UINT32)pWRITECALDATATOOTPParms), pParmsOffset);
    return((void*) pWRITECALDATATOOTPParms);
}

static WRITECALDATATOOTP_OP_FUNC WRITECALDATATOOTPOpFunc = NULL;

TLV2_API void registerWRITECALDATATOOTPHandler(WRITECALDATATOOTP_OP_FUNC fp)
{
    WRITECALDATATOOTPOpFunc = fp;
}

A_BOOL WRITECALDATATOOTPOp(void *pParms)
{
    CMD_WRITECALDATATOOTP_PARMS *pWRITECALDATATOOTPParms = (CMD_WRITECALDATATOOTP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("WRITECALDATATOOTPOp: phyID %u\n", pWRITECALDATATOOTPParms->phyID);
#endif //_DEBUG

    if (NULL != WRITECALDATATOOTPOpFunc) {
        (*WRITECALDATATOOTPOpFunc)(pWRITECALDATATOOTPParms);
    }
    return(TRUE);
}

void* initWRITECALDATATOOTPRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_WRITECALDATATOOTPRSP_PARMS  *pWRITECALDATATOOTPRSPParms = (CMD_WRITECALDATATOOTPRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pWRITECALDATATOOTPRSPParms->status = pParmDict[PARM_STATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pWRITECALDATATOOTPRSPParms->status)) - (A_UINT32)pWRITECALDATATOOTPRSPParms), pParmsOffset);
    return((void*) pWRITECALDATATOOTPRSPParms);
}

static WRITECALDATATOOTPRSP_OP_FUNC WRITECALDATATOOTPRSPOpFunc = NULL;

TLV2_API void registerWRITECALDATATOOTPRSPHandler(WRITECALDATATOOTPRSP_OP_FUNC fp)
{
    WRITECALDATATOOTPRSPOpFunc = fp;
}

A_BOOL WRITECALDATATOOTPRSPOp(void *pParms)
{
    CMD_WRITECALDATATOOTPRSP_PARMS *pWRITECALDATATOOTPRSPParms = (CMD_WRITECALDATATOOTPRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("WRITECALDATATOOTPRSPOp: status %u\n", pWRITECALDATATOOTPRSPParms->status);
#endif //_DEBUG

    if (NULL != WRITECALDATATOOTPRSPOpFunc) {
        (*WRITECALDATATOOTPRSPOpFunc)(pWRITECALDATATOOTPRSPParms);
    }
    return(TRUE);
}
