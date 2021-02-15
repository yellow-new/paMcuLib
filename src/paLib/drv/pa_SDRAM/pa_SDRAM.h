#ifndef __PA_SDRAM_H__
#define __PA_SDRAM_H__

#include "paLib/drv/pa_BaseDrv/pa_BaseDrv.h"

#if drv_sdram
extern unsigned char testValue[];

#define SDRAM_MODEREG_BURST_LENGTH_1 ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2 ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4 ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8 ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2 ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3 ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE ((uint16_t)0x0200)
#define TM_SDRAM_Write8(address, value) testValue[address] = value //(*(uint8_t *)(0xC0000000 + (address)) = (value))
// #define TM_SDRAM_Write8(address, value) (*(uint8_t *)(0xC0000000 + (address)) = (value))
namespace SDRAM
{
    namespace drv
    {
        uint8_t sendCommand(
            uint32_t CommandMode,
            uint32_t Bank,
            uint32_t RefreshNum,
            uint32_t RegVal);
        void setRate();
    } // namespace drv
    void test();
    void init();
} // namespace SDRAM
#endif
#endif // __PA_SDRAM_H__