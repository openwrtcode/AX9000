/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdVerifyCalDbHandler.s
#include "tlv2Inc.h"
#include "cmdVerifyCalDbHandler.h"

void* initVERIFYCALDBOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_VERIFYCALDB_PARMS  *pVERIFYCALDBParms = (CMD_VERIFYCALDB_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pVERIFYCALDBParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pVERIFYCALDBParms->calType = pParmDict[PARM_CALTYPE].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pVERIFYCALDBParms->phyId)) - (A_UINT32)pVERIFYCALDBParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CALTYPE, (A_UINT32)(((A_UINT32)&(pVERIFYCALDBParms->calType)) - (A_UINT32)pVERIFYCALDBParms), pParmsOffset);
    return((void*) pVERIFYCALDBParms);
}

static VERIFYCALDB_OP_FUNC VERIFYCALDBOpFunc = NULL;

TLV2_API void registerVERIFYCALDBHandler(VERIFYCALDB_OP_FUNC fp)
{
    VERIFYCALDBOpFunc = fp;
}

A_BOOL VERIFYCALDBOp(void *pParms)
{
    CMD_VERIFYCALDB_PARMS *pVERIFYCALDBParms = (CMD_VERIFYCALDB_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("VERIFYCALDBOp: phyId %u\n", pVERIFYCALDBParms->phyId);
    A_PRINTF("VERIFYCALDBOp: calType %u\n", pVERIFYCALDBParms->calType);
#endif //_DEBUG

    if (NULL != VERIFYCALDBOpFunc) {
        (*VERIFYCALDBOpFunc)(pVERIFYCALDBParms);
    }
    return(TRUE);
}

void* initVERIFYCALDBRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_VERIFYCALDBRSP_PARMS  *pVERIFYCALDBRSPParms = (CMD_VERIFYCALDBRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pVERIFYCALDBRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pVERIFYCALDBRSPParms->status = pParmDict[PARM_STATUS].v.valU8;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pVERIFYCALDBRSPParms->phyId)) - (A_UINT32)pVERIFYCALDBRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pVERIFYCALDBRSPParms->status)) - (A_UINT32)pVERIFYCALDBRSPParms), pParmsOffset);
    return((void*) pVERIFYCALDBRSPParms);
}

static VERIFYCALDBRSP_OP_FUNC VERIFYCALDBRSPOpFunc = NULL;

TLV2_API void registerVERIFYCALDBRSPHandler(VERIFYCALDBRSP_OP_FUNC fp)
{
    VERIFYCALDBRSPOpFunc = fp;
}

A_BOOL VERIFYCALDBRSPOp(void *pParms)
{
    CMD_VERIFYCALDBRSP_PARMS *pVERIFYCALDBRSPParms = (CMD_VERIFYCALDBRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("VERIFYCALDBRSPOp: phyId %u\n", pVERIFYCALDBRSPParms->phyId);
    A_PRINTF("VERIFYCALDBRSPOp: status %u\n", pVERIFYCALDBRSPParms->status);
#endif //_DEBUG

    if (NULL != VERIFYCALDBRSPOpFunc) {
        (*VERIFYCALDBRSPOpFunc)(pVERIFYCALDBRSPParms);
    }
    return(TRUE);
}
