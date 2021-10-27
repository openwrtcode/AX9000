#===============================================================================
# Copyright (c) 2017-2020 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
#===============================================================================

#if !defined(MSTREAM_UTF)
#define MSTREAM_UTF   16
#endif //!defined(MSTREAM_UTF)

#if !defined(MCHAIN_UTF)
#define MCHAIN_UTF   16
#endif //!defined(MCHAIN_UTF)

#if !defined(MAX_PILOT_UTF)
#define MAX_PILOT_UTF			32
#endif //!defined(MAX_PILOT_UTF)

#if !defined(MAX_RSSIPERCHAIN20MHZ_UTF)
#define MAX_RSSIPERCHAIN20MHZ_UTF           128
#endif //!defined(MAX_RSSIPERCHAIN20MHZ_UTF)

# cmd
CMD= RXStatus

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:stopRx:1:u:0
UINT16:freq:1:u:2412
UINT16:freq2:1:u:0
UINT8:ofdmaLinkDir:1:u:0
UINT8:pad1:1:u:0
UINT32:wifiStandard:1:u:0
PARM_END:

# rsp
RSP= RXStatusRsp

# rsp parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:numOfReports:1:u:0
UINT8:pad2:2:u:0:0
UINT32:totalPackets:1:u:0
UINT32:goodPackets:1:u:0
UINT32:otherError:1:u:0
UINT32:crcPackets:1:u:0
UINT32:decrypErrors:1:u:0
UINT32:rateBit:1:u:0
UINT32:startTime:1:u:0
UINT32:endTime:1:u:0
UINT32:byteCount:1:u:0
UINT32:dontCount:1:u:0
INT32:rssi:1:d:0
INT32:rssic:MCHAIN_UTF:16:d
INT32:rssie:MCHAIN_UTF:16:d
INT32:badrssi:1:d:0
INT32:badrssic:MCHAIN_UTF:16:d
INT32:badrssie:MCHAIN_UTF:16:d
INT32:evm:MSTREAM_UTF:16:d
INT32:badevm:MSTREAM_UTF:16:d
INT32:noisefloorArr:MSTREAM_UTF:16:d
INT32:pilotevm:MAX_PILOT_UTF:32:d
UINT16:chainMask:1:x:0x3
UINT8:bandwidth:1:u:0
UINT8:num20Mhz:1:u:0
UINT8:numChain:1:u:2
UINT8:pad3:3:u:0:0
INT16:rssiPerChain20Mhz:MAX_RSSIPERCHAIN20MHZ_UTF:128:d
PARM_END:
