/* Copyright (c) 2018-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdEepromRead.s
#include "tlv2Inc.h"
#include "cmdEepromRead.h"

void* initEEPROMREADOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_EEPROMREAD_PARMS  *pEEPROMREADParms = (CMD_EEPROMREAD_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pEEPROMREADParms->eepromCalDataSize = pParmDict[PARM_EEPROMCALDATASIZE].v.valU32;
    pEEPROMREADParms->offset = pParmDict[PARM_OFFSET].v.valU32;
    pEEPROMREADParms->size = pParmDict[PARM_SIZE].v.valU32;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_EEPROMCALDATASIZE, (A_UINT32)(((A_UINT32)&(pEEPROMREADParms->eepromCalDataSize)) - (A_UINT32)pEEPROMREADParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OFFSET, (A_UINT32)(((A_UINT32)&(pEEPROMREADParms->offset)) - (A_UINT32)pEEPROMREADParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SIZE, (A_UINT32)(((A_UINT32)&(pEEPROMREADParms->size)) - (A_UINT32)pEEPROMREADParms), pParmsOffset);
    return((void*) pEEPROMREADParms);
}

static EEPROMREAD_OP_FUNC EEPROMREADOpFunc = NULL;

TLV2_API void registerEEPROMREADHandler(EEPROMREAD_OP_FUNC fp)
{
    EEPROMREADOpFunc = fp;
}

A_BOOL EEPROMREADOp(void *pParms)
{
    CMD_EEPROMREAD_PARMS *pEEPROMREADParms = (CMD_EEPROMREAD_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("EEPROMREADOp: eepromCalDataSize %u\n", pEEPROMREADParms->eepromCalDataSize);
    A_PRINTF("EEPROMREADOp: offset %u\n", pEEPROMREADParms->offset);
    A_PRINTF("EEPROMREADOp: size %u\n", pEEPROMREADParms->size);
#endif //_DEBUG

    if (NULL != EEPROMREADOpFunc) {
        (*EEPROMREADOpFunc)(pEEPROMREADParms);
    }
    return(TRUE);
}

void* initEEPROMREADRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_EEPROMREADRSP_PARMS  *pEEPROMREADRSPParms = (CMD_EEPROMREADRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pEEPROMREADRSPParms->status = pParmDict[PARM_STATUS].v.valU8;
    memset(pEEPROMREADRSPParms->pad3, 0, sizeof(pEEPROMREADRSPParms->pad3));
    pEEPROMREADRSPParms->offset = pParmDict[PARM_OFFSET].v.valU32;
    pEEPROMREADRSPParms->size = pParmDict[PARM_SIZE].v.valU32;
    memset(pEEPROMREADRSPParms->data4k, 0, sizeof(pEEPROMREADRSPParms->data4k));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_STATUS, (A_UINT32)(((A_UINT32)&(pEEPROMREADRSPParms->status)) - (A_UINT32)pEEPROMREADRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD3, (A_UINT32)(((A_UINT32)&(pEEPROMREADRSPParms->pad3)) - (A_UINT32)pEEPROMREADRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OFFSET, (A_UINT32)(((A_UINT32)&(pEEPROMREADRSPParms->offset)) - (A_UINT32)pEEPROMREADRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SIZE, (A_UINT32)(((A_UINT32)&(pEEPROMREADRSPParms->size)) - (A_UINT32)pEEPROMREADRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DATA4K, (A_UINT32)(((A_UINT32)&(pEEPROMREADRSPParms->data4k)) - (A_UINT32)pEEPROMREADRSPParms), pParmsOffset);
    return((void*) pEEPROMREADRSPParms);
}

static EEPROMREADRSP_OP_FUNC EEPROMREADRSPOpFunc = NULL;

TLV2_API void registerEEPROMREADRSPHandler(EEPROMREADRSP_OP_FUNC fp)
{
    EEPROMREADRSPOpFunc = fp;
}

A_BOOL EEPROMREADRSPOp(void *pParms)
{
    CMD_EEPROMREADRSP_PARMS *pEEPROMREADRSPParms = (CMD_EEPROMREADRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("EEPROMREADRSPOp: status %u\n", pEEPROMREADRSPParms->status);
    for (i = 0; i < 3 ; i++)
    {
        A_PRINTF("EEPROMREADRSPOp: pad3 %u\n", pEEPROMREADRSPParms->pad3[i]);
    }
    A_PRINTF("EEPROMREADRSPOp: offset %u\n", pEEPROMREADRSPParms->offset);
    A_PRINTF("EEPROMREADRSPOp: size %u\n", pEEPROMREADRSPParms->size);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 4096 entries
    {
        A_PRINTF("EEPROMREADRSPOp: data4k 0x%x\n", pEEPROMREADRSPParms->data4k[i]);
    }
#endif //_DEBUG

    if (NULL != EEPROMREADRSPOpFunc) {
        (*EEPROMREADRSPOpFunc)(pEEPROMREADRSPParms);
    }
    return(TRUE);
}
