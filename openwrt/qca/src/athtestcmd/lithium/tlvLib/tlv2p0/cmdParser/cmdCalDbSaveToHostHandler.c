/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdCalDbSaveToHostHandler.s
#include "tlv2Inc.h"
#include "cmdCalDbSaveToHostHandler.h"

void* initCALDBSAVETOHOSTOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_CALDBSAVETOHOST_PARMS  *pCALDBSAVETOHOSTParms = (CMD_CALDBSAVETOHOST_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pCALDBSAVETOHOSTParms->phyId = pParmDict[PARM_PHYID].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pCALDBSAVETOHOSTParms->phyId)) - (A_UINT32)pCALDBSAVETOHOSTParms), pParmsOffset);
    return((void*) pCALDBSAVETOHOSTParms);
}

static CALDBSAVETOHOST_OP_FUNC CALDBSAVETOHOSTOpFunc = NULL;

TLV2_API void registerCALDBSAVETOHOSTHandler(CALDBSAVETOHOST_OP_FUNC fp)
{
    CALDBSAVETOHOSTOpFunc = fp;
}

A_BOOL CALDBSAVETOHOSTOp(void *pParms)
{
    CMD_CALDBSAVETOHOST_PARMS *pCALDBSAVETOHOSTParms = (CMD_CALDBSAVETOHOST_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("CALDBSAVETOHOSTOp: phyId %u\n", pCALDBSAVETOHOSTParms->phyId);
#endif //_DEBUG

    if (NULL != CALDBSAVETOHOSTOpFunc) {
        (*CALDBSAVETOHOSTOpFunc)(pCALDBSAVETOHOSTParms);
    }
    return(TRUE);
}

void* initCALDBSAVETOHOSTRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_CALDBSAVETOHOSTRSP_PARMS  *pCALDBSAVETOHOSTRSPParms = (CMD_CALDBSAVETOHOSTRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pCALDBSAVETOHOSTRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pCALDBSAVETOHOSTRSPParms->status = pParmDict[PARM_STATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pCALDBSAVETOHOSTRSPParms->phyId)) - (A_UINT32)pCALDBSAVETOHOSTRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pCALDBSAVETOHOSTRSPParms->status)) - (A_UINT32)pCALDBSAVETOHOSTRSPParms), pParmsOffset);
    return((void*) pCALDBSAVETOHOSTRSPParms);
}

static CALDBSAVETOHOSTRSP_OP_FUNC CALDBSAVETOHOSTRSPOpFunc = NULL;

TLV2_API void registerCALDBSAVETOHOSTRSPHandler(CALDBSAVETOHOSTRSP_OP_FUNC fp)
{
    CALDBSAVETOHOSTRSPOpFunc = fp;
}

A_BOOL CALDBSAVETOHOSTRSPOp(void *pParms)
{
    CMD_CALDBSAVETOHOSTRSP_PARMS *pCALDBSAVETOHOSTRSPParms = (CMD_CALDBSAVETOHOSTRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("CALDBSAVETOHOSTRSPOp: phyId %u\n", pCALDBSAVETOHOSTRSPParms->phyId);
    A_PRINTF("CALDBSAVETOHOSTRSPOp: status %u\n", pCALDBSAVETOHOSTRSPParms->status);
#endif //_DEBUG

    if (NULL != CALDBSAVETOHOSTRSPOpFunc) {
        (*CALDBSAVETOHOSTRSPOpFunc)(pCALDBSAVETOHOSTRSPParms);
    }
    return(TRUE);
}
