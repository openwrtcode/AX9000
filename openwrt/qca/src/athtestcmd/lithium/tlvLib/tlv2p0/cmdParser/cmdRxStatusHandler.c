/* Copyright (c) 2017-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdRxStatusHandler.s
#include "tlv2Inc.h"
#include "cmdRxStatusHandler.h"

void* initRXSTATUSOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_RXSTATUS_PARMS  *pRXSTATUSParms = (CMD_RXSTATUS_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pRXSTATUSParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pRXSTATUSParms->stopRx = pParmDict[PARM_STOPRX].v.valU8;
    pRXSTATUSParms->freq = pParmDict[PARM_FREQ].v.valU16;
    pRXSTATUSParms->freq2 = pParmDict[PARM_FREQ2].v.valU16;
    pRXSTATUSParms->ofdmaLinkDir = pParmDict[PARM_OFDMALINKDIR].v.valU8;
    pRXSTATUSParms->pad1 = pParmDict[PARM_PAD1].v.valU8;
    pRXSTATUSParms->wifiStandard = pParmDict[PARM_WIFISTANDARD].v.valU32;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pRXSTATUSParms->phyId)) - (A_UINT32)pRXSTATUSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STOPRX, (A_UINT32)(((A_UINT32)&(pRXSTATUSParms->stopRx)) - (A_UINT32)pRXSTATUSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FREQ, (A_UINT32)(((A_UINT32)&(pRXSTATUSParms->freq)) - (A_UINT32)pRXSTATUSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FREQ2, (A_UINT32)(((A_UINT32)&(pRXSTATUSParms->freq2)) - (A_UINT32)pRXSTATUSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OFDMALINKDIR, (A_UINT32)(((A_UINT32)&(pRXSTATUSParms->ofdmaLinkDir)) - (A_UINT32)pRXSTATUSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD1, (A_UINT32)(((A_UINT32)&(pRXSTATUSParms->pad1)) - (A_UINT32)pRXSTATUSParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_WIFISTANDARD, (A_UINT32)(((A_UINT32)&(pRXSTATUSParms->wifiStandard)) - (A_UINT32)pRXSTATUSParms), pParmsOffset);
    return((void*) pRXSTATUSParms);
}

static RXSTATUS_OP_FUNC RXSTATUSOpFunc = NULL;

TLV2_API void registerRXSTATUSHandler(RXSTATUS_OP_FUNC fp)
{
    RXSTATUSOpFunc = fp;
}

A_BOOL RXSTATUSOp(void *pParms)
{
    CMD_RXSTATUS_PARMS *pRXSTATUSParms = (CMD_RXSTATUS_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("RXSTATUSOp: phyId %u\n", pRXSTATUSParms->phyId);
    A_PRINTF("RXSTATUSOp: stopRx %u\n", pRXSTATUSParms->stopRx);
    A_PRINTF("RXSTATUSOp: freq %u\n", pRXSTATUSParms->freq);
    A_PRINTF("RXSTATUSOp: freq2 %u\n", pRXSTATUSParms->freq2);
    A_PRINTF("RXSTATUSOp: ofdmaLinkDir %u\n", pRXSTATUSParms->ofdmaLinkDir);
    A_PRINTF("RXSTATUSOp: pad1 %u\n", pRXSTATUSParms->pad1);
    A_PRINTF("RXSTATUSOp: wifiStandard %u\n", pRXSTATUSParms->wifiStandard);
#endif //_DEBUG

    if (NULL != RXSTATUSOpFunc) {
        (*RXSTATUSOpFunc)(pRXSTATUSParms);
    }
    return(TRUE);
}

void* initRXSTATUSRSPOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_RXSTATUSRSP_PARMS  *pRXSTATUSRSPParms = (CMD_RXSTATUSRSP_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pRXSTATUSRSPParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pRXSTATUSRSPParms->numOfReports = pParmDict[PARM_NUMOFREPORTS].v.valU8;
    for (i = 0; i < 2 ; i++)
    {
        pRXSTATUSRSPParms->pad2[i] = pParmDict[PARM_PAD2].v.ptU8[i];
    }
    pRXSTATUSRSPParms->totalPackets = pParmDict[PARM_TOTALPACKETS].v.valU32;
    pRXSTATUSRSPParms->goodPackets = pParmDict[PARM_GOODPACKETS].v.valU32;
    pRXSTATUSRSPParms->otherError = pParmDict[PARM_OTHERERROR].v.valU32;
    pRXSTATUSRSPParms->crcPackets = pParmDict[PARM_CRCPACKETS].v.valU32;
    pRXSTATUSRSPParms->decrypErrors = pParmDict[PARM_DECRYPERRORS].v.valU32;
    pRXSTATUSRSPParms->rateBit = pParmDict[PARM_RATEBIT].v.valU32;
    pRXSTATUSRSPParms->startTime = pParmDict[PARM_STARTTIME].v.valU32;
    pRXSTATUSRSPParms->endTime = pParmDict[PARM_ENDTIME].v.valU32;
    pRXSTATUSRSPParms->byteCount = pParmDict[PARM_BYTECOUNT].v.valU32;
    pRXSTATUSRSPParms->dontCount = pParmDict[PARM_DONTCOUNT].v.valU32;
    pRXSTATUSRSPParms->rssi = pParmDict[PARM_RSSI].v.valS32;
    memset(pRXSTATUSRSPParms->rssic, 0, sizeof(pRXSTATUSRSPParms->rssic));
    memset(pRXSTATUSRSPParms->rssie, 0, sizeof(pRXSTATUSRSPParms->rssie));
    pRXSTATUSRSPParms->badrssi = pParmDict[PARM_BADRSSI].v.valS32;
    memset(pRXSTATUSRSPParms->badrssic, 0, sizeof(pRXSTATUSRSPParms->badrssic));
    memset(pRXSTATUSRSPParms->badrssie, 0, sizeof(pRXSTATUSRSPParms->badrssie));
    memset(pRXSTATUSRSPParms->evm, 0, sizeof(pRXSTATUSRSPParms->evm));
    memset(pRXSTATUSRSPParms->badevm, 0, sizeof(pRXSTATUSRSPParms->badevm));
    memset(pRXSTATUSRSPParms->noisefloorArr, 0, sizeof(pRXSTATUSRSPParms->noisefloorArr));
    memset(pRXSTATUSRSPParms->pilotevm, 0, sizeof(pRXSTATUSRSPParms->pilotevm));
    pRXSTATUSRSPParms->chainMask = pParmDict[PARM_CHAINMASK].v.valU16;
    pRXSTATUSRSPParms->bandwidth = pParmDict[PARM_BANDWIDTH].v.valU8;
    pRXSTATUSRSPParms->num20Mhz = pParmDict[PARM_NUM20MHZ].v.valU8;
    pRXSTATUSRSPParms->numChain = pParmDict[PARM_NUMCHAIN].v.valU8;
    memset(pRXSTATUSRSPParms->pad3, 0, sizeof(pRXSTATUSRSPParms->pad3));
    for (i = 0; i < 2 ; i++)
    {
        pRXSTATUSRSPParms->pad3[i] = pParmDict[PARM_PAD3].v.ptU8[i];
    }
    memset(pRXSTATUSRSPParms->rssiPerChain20Mhz, 0, sizeof(pRXSTATUSRSPParms->rssiPerChain20Mhz));

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->phyId)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMOFREPORTS, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->numOfReports)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD2, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->pad2)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TOTALPACKETS, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->totalPackets)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GOODPACKETS, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->goodPackets)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_OTHERERROR, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->otherError)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CRCPACKETS, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->crcPackets)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DECRYPERRORS, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->decrypErrors)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEBIT, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->rateBit)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_STARTTIME, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->startTime)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ENDTIME, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->endTime)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BYTECOUNT, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->byteCount)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DONTCOUNT, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->dontCount)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RSSI, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->rssi)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RSSIC, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->rssic)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RSSIE, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->rssie)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BADRSSI, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->badrssi)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BADRSSIC, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->badrssic)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BADRSSIE, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->badrssie)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_EVM, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->evm)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BADEVM, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->badevm)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NOISEFLOORARR, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->noisefloorArr)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PILOTEVM, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->pilotevm)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CHAINMASK, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->chainMask)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BANDWIDTH, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->bandwidth)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUM20MHZ, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->num20Mhz)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NUMCHAIN, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->numChain)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD3, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->pad3)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RSSIPERCHAIN20MHZ, (A_UINT32)(((A_UINT32)&(pRXSTATUSRSPParms->rssiPerChain20Mhz)) - (A_UINT32)pRXSTATUSRSPParms), pParmsOffset);
    return((void*) pRXSTATUSRSPParms);
}

static RXSTATUSRSP_OP_FUNC RXSTATUSRSPOpFunc = NULL;

TLV2_API void registerRXSTATUSRSPHandler(RXSTATUSRSP_OP_FUNC fp)
{
    RXSTATUSRSPOpFunc = fp;
}

A_BOOL RXSTATUSRSPOp(void *pParms)
{
    CMD_RXSTATUSRSP_PARMS *pRXSTATUSRSPParms = (CMD_RXSTATUSRSP_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("RXSTATUSRSPOp: phyId %u\n", pRXSTATUSRSPParms->phyId);
    A_PRINTF("RXSTATUSRSPOp: numOfReports %u\n", pRXSTATUSRSPParms->numOfReports);
    for (i = 0; i < 2 ; i++)
    {
        A_PRINTF("RXSTATUSRSPOp: pad2 %u\n", pRXSTATUSRSPParms->pad2[i]);
    }
    A_PRINTF("RXSTATUSRSPOp: totalPackets %u\n", pRXSTATUSRSPParms->totalPackets);
    A_PRINTF("RXSTATUSRSPOp: goodPackets %u\n", pRXSTATUSRSPParms->goodPackets);
    A_PRINTF("RXSTATUSRSPOp: otherError %u\n", pRXSTATUSRSPParms->otherError);
    A_PRINTF("RXSTATUSRSPOp: crcPackets %u\n", pRXSTATUSRSPParms->crcPackets);
    A_PRINTF("RXSTATUSRSPOp: decrypErrors %u\n", pRXSTATUSRSPParms->decrypErrors);
    A_PRINTF("RXSTATUSRSPOp: rateBit %u\n", pRXSTATUSRSPParms->rateBit);
    A_PRINTF("RXSTATUSRSPOp: startTime %u\n", pRXSTATUSRSPParms->startTime);
    A_PRINTF("RXSTATUSRSPOp: endTime %u\n", pRXSTATUSRSPParms->endTime);
    A_PRINTF("RXSTATUSRSPOp: byteCount %u\n", pRXSTATUSRSPParms->byteCount);
    A_PRINTF("RXSTATUSRSPOp: dontCount %u\n", pRXSTATUSRSPParms->dontCount);
    A_PRINTF("RXSTATUSRSPOp: rssi %d\n", pRXSTATUSRSPParms->rssi);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 16 entries
    {
        A_PRINTF("RXSTATUSRSPOp: rssic %d\n", pRXSTATUSRSPParms->rssic[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 16 entries
    {
        A_PRINTF("RXSTATUSRSPOp: rssie %d\n", pRXSTATUSRSPParms->rssie[i]);
    }
    A_PRINTF("RXSTATUSRSPOp: badrssi %d\n", pRXSTATUSRSPParms->badrssi);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 16 entries
    {
        A_PRINTF("RXSTATUSRSPOp: badrssic %d\n", pRXSTATUSRSPParms->badrssic[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 16 entries
    {
        A_PRINTF("RXSTATUSRSPOp: badrssie %d\n", pRXSTATUSRSPParms->badrssie[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 16 entries
    {
        A_PRINTF("RXSTATUSRSPOp: evm %d\n", pRXSTATUSRSPParms->evm[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 16 entries
    {
        A_PRINTF("RXSTATUSRSPOp: badevm %d\n", pRXSTATUSRSPParms->badevm[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 16 entries
    {
        A_PRINTF("RXSTATUSRSPOp: noisefloorArr %d\n", pRXSTATUSRSPParms->noisefloorArr[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 32 entries
    {
        A_PRINTF("RXSTATUSRSPOp: pilotevm %d\n", pRXSTATUSRSPParms->pilotevm[i]);
    }
    A_PRINTF("RXSTATUSRSPOp: chainMask 0x%x\n", pRXSTATUSRSPParms->chainMask);
    A_PRINTF("RXSTATUSRSPOp: bandwidth %u\n", pRXSTATUSRSPParms->bandwidth);
    A_PRINTF("RXSTATUSRSPOp: num20Mhz %u\n", pRXSTATUSRSPParms->num20Mhz);
    A_PRINTF("RXSTATUSRSPOp: numChain %u\n", pRXSTATUSRSPParms->numChain);
    for (i = 0; i < 3 ; i++)
    {
        A_PRINTF("RXSTATUSRSPOp: pad3 %u\n", pRXSTATUSRSPParms->pad3[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 128 entries
    {
        A_PRINTF("RXSTATUSRSPOp: rssiPerChain20Mhz %d\n", pRXSTATUSRSPParms->rssiPerChain20Mhz[i]);
    }
#endif //_DEBUG

    if (NULL != RXSTATUSRSPOpFunc) {
        (*RXSTATUSRSPOpFunc)(pRXSTATUSRSPParms);
    }
    return(TRUE);
}
