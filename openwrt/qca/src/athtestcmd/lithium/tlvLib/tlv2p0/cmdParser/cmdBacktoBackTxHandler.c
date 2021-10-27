/* Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
// This is an auto-generated file from input/cmdBacktoBackTxHandler.s
#include "tlv2Inc.h"
#include "cmdBacktoBackTxHandler.h"

void* initBACKTOBACKTXOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)
{
    int i, j; 	//for initializing array parameter
    CMD_BACKTOBACKTX_PARMS  *pBACKTOBACKTXParms = (CMD_BACKTOBACKTX_PARMS *)pParmsCommon;

    if (pParmsCommon == NULL) return (NULL);

    i = j = 0;	//assign a number to avoid warning in case i and j are not used

    // Populate the parm structure with initial values
    pBACKTOBACKTXParms->phyId = pParmDict[PARM_PHYID].v.valU8;
    pBACKTOBACKTXParms->txMode = pParmDict[PARM_TXMODE].v.valU8;
    memset(pBACKTOBACKTXParms->lmfreq, 0, sizeof(pBACKTOBACKTXParms->lmfreq));
    pBACKTOBACKTXParms->freq2 = pParmDict[PARM_FREQ2].v.valU16;
    memset(pBACKTOBACKTXParms->lmchainMask, 0, sizeof(pBACKTOBACKTXParms->lmchainMask));
    pBACKTOBACKTXParms->wlanMode = pParmDict[PARM_WLANMODE].v.valU8;
    pBACKTOBACKTXParms->bandwidth = pParmDict[PARM_BANDWIDTH].v.valU8;
    pBACKTOBACKTXParms->gI = pParmDict[PARM_GI].v.valU8;
    pBACKTOBACKTXParms->antenna = pParmDict[PARM_ANTENNA].v.valU8;
    pBACKTOBACKTXParms->enANI = pParmDict[PARM_ENANI].v.valU8;
    pBACKTOBACKTXParms->scramblerOff = pParmDict[PARM_SCRAMBLEROFF].v.valU8;
    pBACKTOBACKTXParms->aifsn = pParmDict[PARM_AIFSN].v.valU8;
    pBACKTOBACKTXParms->broadcast = pParmDict[PARM_BROADCAST].v.valU8;
    pBACKTOBACKTXParms->agg = pParmDict[PARM_AGG].v.valU8;
    pBACKTOBACKTXParms->shortGuard = pParmDict[PARM_SHORTGUARD].v.valU8;
    pBACKTOBACKTXParms->dutyCycle = pParmDict[PARM_DUTYCYCLE].v.valU8;
    pBACKTOBACKTXParms->padding = pParmDict[PARM_PADDING].v.valU8;
    pBACKTOBACKTXParms->flags = pParmDict[PARM_FLAGS].v.valU32;
    pBACKTOBACKTXParms->ir = pParmDict[PARM_IR].v.valU32;
    memset(pBACKTOBACKTXParms->lmpktSz, 0, sizeof(pBACKTOBACKTXParms->lmpktSz));
    memset(pBACKTOBACKTXParms->dataPattern, 0, sizeof(pBACKTOBACKTXParms->dataPattern));
    memset(pBACKTOBACKTXParms->lmtxNumPackets, 0, sizeof(pBACKTOBACKTXParms->lmtxNumPackets));
    pBACKTOBACKTXParms->txPattern = pParmDict[PARM_TXPATTERN].v.valU16;
    pBACKTOBACKTXParms->nPattern = pParmDict[PARM_NPATTERN].v.valU8;
    pBACKTOBACKTXParms->tpcm = pParmDict[PARM_TPCM].v.valU8;
    pBACKTOBACKTXParms->gainIdx = pParmDict[PARM_GAINIDX].v.valU8;
    pBACKTOBACKTXParms->dacGain = pParmDict[PARM_DACGAIN].v.valS8;
    pBACKTOBACKTXParms->dacGainEnd = pParmDict[PARM_DACGAINEND].v.valS8;
    pBACKTOBACKTXParms->dacGainStep = pParmDict[PARM_DACGAINSTEP].v.valS8;
    pBACKTOBACKTXParms->paConfig = pParmDict[PARM_PACONFIG].v.valU8;
    pBACKTOBACKTXParms->paConfigEnd = pParmDict[PARM_PACONFIGEND].v.valU8;
    pBACKTOBACKTXParms->paConfigStep = pParmDict[PARM_PACONFIGSTEP].v.valU8;
    pBACKTOBACKTXParms->pad1 = pParmDict[PARM_PAD1].v.valU8;
    pBACKTOBACKTXParms->rateBitIndex = pParmDict[PARM_RATEBITINDEX].v.valU16;
    memset(pBACKTOBACKTXParms->lmrateIndex, 0, sizeof(pBACKTOBACKTXParms->lmrateIndex));
    for (i = 0; i < 3 ; i++)
    {
        pBACKTOBACKTXParms->rateMask[i] = pParmDict[PARM_RATEMASK].v.ptU32[i];
    }
    memset(pBACKTOBACKTXParms->rateMask11AC, 0, sizeof(pBACKTOBACKTXParms->rateMask11AC));
    pBACKTOBACKTXParms->rateMaskAC160 = pParmDict[PARM_RATEMASKAC160].v.valU32;
    for (i = 0; i < 24 ; i++)
    {
        pBACKTOBACKTXParms->pwrGainStart[i] = pParmDict[PARM_PWRGAINSTART].v.ptS32[i];
    }
    for (i = 0; i < 24 ; i++)
    {
        pBACKTOBACKTXParms->pwrGainEnd[i] = pParmDict[PARM_PWRGAINEND].v.ptS32[i];
    }
    for (i = 0; i < 24 ; i++)
    {
        pBACKTOBACKTXParms->pwrGainStep[i] = pParmDict[PARM_PWRGAINSTEP].v.ptS32[i];
    }
    for (i = 0; i < 40 ; i++)
    {
        pBACKTOBACKTXParms->pwrGainStart11AC[i] = pParmDict[PARM_PWRGAINSTART11AC].v.ptS32[i];
    }
    for (i = 0; i < 40 ; i++)
    {
        pBACKTOBACKTXParms->pwrGainEnd11AC[i] = pParmDict[PARM_PWRGAINEND11AC].v.ptS32[i];
    }
    for (i = 0; i < 40 ; i++)
    {
        pBACKTOBACKTXParms->pwrGainStep11AC[i] = pParmDict[PARM_PWRGAINSTEP11AC].v.ptS32[i];
    }
    for (i = 0; i < 8 ; i++)
    {
        pBACKTOBACKTXParms->pwrGainStartAC160[i] = pParmDict[PARM_PWRGAINSTARTAC160].v.ptS32[i];
    }
    for (i = 0; i < 8 ; i++)
    {
        pBACKTOBACKTXParms->pwrGainEndAC160[i] = pParmDict[PARM_PWRGAINENDAC160].v.ptS32[i];
    }
    for (i = 0; i < 8 ; i++)
    {
        pBACKTOBACKTXParms->pwrGainStepAC160[i] = pParmDict[PARM_PWRGAINSTEPAC160].v.ptS32[i];
    }
    memset(pBACKTOBACKTXParms->lmtxPower, 0, sizeof(pBACKTOBACKTXParms->lmtxPower));
    for (i = 0; i < 6 ; i++)
    {
        pBACKTOBACKTXParms->bssid[i] = pParmDict[PARM_BSSID].v.ptU8[i];
    }
    for (i = 0; i < 6 ; i++)
    {
        pBACKTOBACKTXParms->txStation[i] = pParmDict[PARM_TXSTATION].v.ptU8[i];
    }
    for (i = 0; i < 6 ; i++)
    {
        pBACKTOBACKTXParms->rxStation[i] = pParmDict[PARM_RXSTATION].v.ptU8[i];
    }
    pBACKTOBACKTXParms->wifiStandard = pParmDict[PARM_WIFISTANDARD].v.valU32;
    pBACKTOBACKTXParms->NSS = pParmDict[PARM_NSS].v.valU32;
    pBACKTOBACKTXParms->rate = pParmDict[PARM_RATE].v.valU8;
    pBACKTOBACKTXParms->tableLength = pParmDict[PARM_TABLELENGTH].v.valU16;
    pBACKTOBACKTXParms->cycleTime = pParmDict[PARM_CYCLETIME].v.valU16;

    // Make up ParmOffsetTbl
    resetParmOffsetFields();
    fillParmOffsetTbl((A_UINT32)PARM_PHYID, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->phyId)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TXMODE, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->txMode)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LMFREQ, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->lmfreq)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FREQ2, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->freq2)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LMCHAINMASK, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->lmchainMask)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_WLANMODE, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->wlanMode)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BANDWIDTH, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->bandwidth)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GI, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->gI)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ANTENNA, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->antenna)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_ENANI, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->enANI)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SCRAMBLEROFF, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->scramblerOff)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_AIFSN, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->aifsn)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BROADCAST, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->broadcast)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_AGG, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->agg)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_SHORTGUARD, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->shortGuard)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DUTYCYCLE, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->dutyCycle)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PADDING, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->padding)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_FLAGS, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->flags)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_IR, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->ir)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LMPKTSZ, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->lmpktSz)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DATAPATTERN, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->dataPattern)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LMTXNUMPACKETS, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->lmtxNumPackets)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TXPATTERN, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->txPattern)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NPATTERN, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->nPattern)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TPCM, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->tpcm)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_GAINIDX, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->gainIdx)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DACGAIN, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->dacGain)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DACGAINEND, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->dacGainEnd)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_DACGAINSTEP, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->dacGainStep)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PACONFIG, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->paConfig)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PACONFIGEND, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->paConfigEnd)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PACONFIGSTEP, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->paConfigStep)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PAD1, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->pad1)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEBITINDEX, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->rateBitIndex)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LMRATEINDEX, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->lmrateIndex)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASK, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->rateMask)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASK11AC, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->rateMask11AC)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATEMASKAC160, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->rateMaskAC160)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINSTART, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->pwrGainStart)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINEND, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->pwrGainEnd)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINSTEP, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->pwrGainStep)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINSTART11AC, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->pwrGainStart11AC)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINEND11AC, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->pwrGainEnd11AC)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINSTEP11AC, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->pwrGainStep11AC)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINSTARTAC160, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->pwrGainStartAC160)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINENDAC160, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->pwrGainEndAC160)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_PWRGAINSTEPAC160, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->pwrGainStepAC160)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_LMTXPOWER, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->lmtxPower)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_BSSID, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->bssid)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TXSTATION, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->txStation)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RXSTATION, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->rxStation)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_WIFISTANDARD, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->wifiStandard)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_NSS, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->NSS)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_RATE, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->rate)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_TABLELENGTH, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->tableLength)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    fillParmOffsetTbl((A_UINT32)PARM_CYCLETIME, (A_UINT32)(((A_UINT32)&(pBACKTOBACKTXParms->cycleTime)) - (A_UINT32)pBACKTOBACKTXParms), pParmsOffset);
    return((void*) pBACKTOBACKTXParms);
}

static BACKTOBACKTX_OP_FUNC BACKTOBACKTXOpFunc = NULL;

TLV2_API void registerBACKTOBACKTXHandler(BACKTOBACKTX_OP_FUNC fp)
{
    BACKTOBACKTXOpFunc = fp;
}

A_BOOL BACKTOBACKTXOp(void *pParms)
{
    CMD_BACKTOBACKTX_PARMS *pBACKTOBACKTXParms = (CMD_BACKTOBACKTX_PARMS *)pParms;

#if 0 //for debugging, comment out this line, and uncomment the line below
//#ifdef _DEBUG
    int i; 	//for initializing array parameter
    i = 0;	//assign a number to avoid warning in case i is not used

    A_PRINTF("BACKTOBACKTXOp: phyId %u\n", pBACKTOBACKTXParms->phyId);
    A_PRINTF("BACKTOBACKTXOp: txMode %u\n", pBACKTOBACKTXParms->txMode);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 25 entries
    {
        A_PRINTF("BACKTOBACKTXOp: lmfreq %u\n", pBACKTOBACKTXParms->lmfreq[i]);
    }
    A_PRINTF("BACKTOBACKTXOp: freq2 %u\n", pBACKTOBACKTXParms->freq2);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 25 entries
    {
        A_PRINTF("BACKTOBACKTXOp: lmchainMask %u\n", pBACKTOBACKTXParms->lmchainMask[i]);
    }
    A_PRINTF("BACKTOBACKTXOp: wlanMode %u\n", pBACKTOBACKTXParms->wlanMode);
    A_PRINTF("BACKTOBACKTXOp: bandwidth %u\n", pBACKTOBACKTXParms->bandwidth);
    A_PRINTF("BACKTOBACKTXOp: gI %u\n", pBACKTOBACKTXParms->gI);
    A_PRINTF("BACKTOBACKTXOp: antenna %u\n", pBACKTOBACKTXParms->antenna);
    A_PRINTF("BACKTOBACKTXOp: enANI %u\n", pBACKTOBACKTXParms->enANI);
    A_PRINTF("BACKTOBACKTXOp: scramblerOff %u\n", pBACKTOBACKTXParms->scramblerOff);
    A_PRINTF("BACKTOBACKTXOp: aifsn %u\n", pBACKTOBACKTXParms->aifsn);
    A_PRINTF("BACKTOBACKTXOp: broadcast %u\n", pBACKTOBACKTXParms->broadcast);
    A_PRINTF("BACKTOBACKTXOp: agg %u\n", pBACKTOBACKTXParms->agg);
    A_PRINTF("BACKTOBACKTXOp: shortGuard %u\n", pBACKTOBACKTXParms->shortGuard);
    A_PRINTF("BACKTOBACKTXOp: dutyCycle %u\n", pBACKTOBACKTXParms->dutyCycle);
    A_PRINTF("BACKTOBACKTXOp: padding %u\n", pBACKTOBACKTXParms->padding);
    A_PRINTF("BACKTOBACKTXOp: flags 0x%x\n", pBACKTOBACKTXParms->flags);
    A_PRINTF("BACKTOBACKTXOp: ir %u\n", pBACKTOBACKTXParms->ir);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 25 entries
    {
        A_PRINTF("BACKTOBACKTXOp: lmpktSz %u\n", pBACKTOBACKTXParms->lmpktSz[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 40 entries
    {
        A_PRINTF("BACKTOBACKTXOp: dataPattern %u\n", pBACKTOBACKTXParms->dataPattern[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 25 entries
    {
        A_PRINTF("BACKTOBACKTXOp: lmtxNumPackets %u\n", pBACKTOBACKTXParms->lmtxNumPackets[i]);
    }
    A_PRINTF("BACKTOBACKTXOp: txPattern %u\n", pBACKTOBACKTXParms->txPattern);
    A_PRINTF("BACKTOBACKTXOp: nPattern %u\n", pBACKTOBACKTXParms->nPattern);
    A_PRINTF("BACKTOBACKTXOp: tpcm %u\n", pBACKTOBACKTXParms->tpcm);
    A_PRINTF("BACKTOBACKTXOp: gainIdx %u\n", pBACKTOBACKTXParms->gainIdx);
    A_PRINTF("BACKTOBACKTXOp: dacGain %d\n", pBACKTOBACKTXParms->dacGain);
    A_PRINTF("BACKTOBACKTXOp: dacGainEnd %d\n", pBACKTOBACKTXParms->dacGainEnd);
    A_PRINTF("BACKTOBACKTXOp: dacGainStep %d\n", pBACKTOBACKTXParms->dacGainStep);
    A_PRINTF("BACKTOBACKTXOp: paConfig %u\n", pBACKTOBACKTXParms->paConfig);
    A_PRINTF("BACKTOBACKTXOp: paConfigEnd %u\n", pBACKTOBACKTXParms->paConfigEnd);
    A_PRINTF("BACKTOBACKTXOp: paConfigStep %u\n", pBACKTOBACKTXParms->paConfigStep);
    A_PRINTF("BACKTOBACKTXOp: pad1 %u\n", pBACKTOBACKTXParms->pad1);
    A_PRINTF("BACKTOBACKTXOp: rateBitIndex %u\n", pBACKTOBACKTXParms->rateBitIndex);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 25 entries
    {
        A_PRINTF("BACKTOBACKTXOp: lmrateIndex %u\n", pBACKTOBACKTXParms->lmrateIndex[i]);
    }
    for (i = 0; i < 3 ; i++)
    {
        A_PRINTF("BACKTOBACKTXOp: rateMask 0x%x\n", pBACKTOBACKTXParms->rateMask[i]);
    }
    for (i = 0; i < 5 ; i++)
    {
        A_PRINTF("BACKTOBACKTXOp: rateMask11AC 0x%x\n", pBACKTOBACKTXParms->rateMask11AC[i]);
    }
    A_PRINTF("BACKTOBACKTXOp: rateMaskAC160 0x%x\n", pBACKTOBACKTXParms->rateMaskAC160);
    for (i = 0; i < 8 ; i++) // can be modified to print up to 24 entries
    {
        A_PRINTF("BACKTOBACKTXOp: pwrGainStart 0x%x\n", pBACKTOBACKTXParms->pwrGainStart[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 24 entries
    {
        A_PRINTF("BACKTOBACKTXOp: pwrGainEnd 0x%x\n", pBACKTOBACKTXParms->pwrGainEnd[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 24 entries
    {
        A_PRINTF("BACKTOBACKTXOp: pwrGainStep 0x%x\n", pBACKTOBACKTXParms->pwrGainStep[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 40 entries
    {
        A_PRINTF("BACKTOBACKTXOp: pwrGainStart11AC 0x%x\n", pBACKTOBACKTXParms->pwrGainStart11AC[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 40 entries
    {
        A_PRINTF("BACKTOBACKTXOp: pwrGainEnd11AC 0x%x\n", pBACKTOBACKTXParms->pwrGainEnd11AC[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 40 entries
    {
        A_PRINTF("BACKTOBACKTXOp: pwrGainStep11AC 0x%x\n", pBACKTOBACKTXParms->pwrGainStep11AC[i]);
    }
    for (i = 0; i < 8 ; i++)
    {
        A_PRINTF("BACKTOBACKTXOp: pwrGainStartAC160 0x%x\n", pBACKTOBACKTXParms->pwrGainStartAC160[i]);
    }
    for (i = 0; i < 8 ; i++)
    {
        A_PRINTF("BACKTOBACKTXOp: pwrGainEndAC160 0x%x\n", pBACKTOBACKTXParms->pwrGainEndAC160[i]);
    }
    for (i = 0; i < 8 ; i++)
    {
        A_PRINTF("BACKTOBACKTXOp: pwrGainStepAC160 0x%x\n", pBACKTOBACKTXParms->pwrGainStepAC160[i]);
    }
    for (i = 0; i < 8 ; i++) // can be modified to print up to 25 entries
    {
        A_PRINTF("BACKTOBACKTXOp: lmtxPower %u\n", pBACKTOBACKTXParms->lmtxPower[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("BACKTOBACKTXOp: bssid 0x%x\n", pBACKTOBACKTXParms->bssid[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("BACKTOBACKTXOp: txStation 0x%x\n", pBACKTOBACKTXParms->txStation[i]);
    }
    for (i = 0; i < 6 ; i++)
    {
        A_PRINTF("BACKTOBACKTXOp: rxStation 0x%x\n", pBACKTOBACKTXParms->rxStation[i]);
    }
    A_PRINTF("BACKTOBACKTXOp: wifiStandard %u\n", pBACKTOBACKTXParms->wifiStandard);
    A_PRINTF("BACKTOBACKTXOp: NSS %u\n", pBACKTOBACKTXParms->NSS);
    A_PRINTF("BACKTOBACKTXOp: rate %u\n", pBACKTOBACKTXParms->rate);
    A_PRINTF("BACKTOBACKTXOp: tableLength %u\n", pBACKTOBACKTXParms->tableLength);
    A_PRINTF("BACKTOBACKTXOp: cycleTime %u\n", pBACKTOBACKTXParms->cycleTime);
#endif //_DEBUG

    if (NULL != BACKTOBACKTXOpFunc) {
        (*BACKTOBACKTXOpFunc)(pBACKTOBACKTXParms);
    }
    return(TRUE);
}
