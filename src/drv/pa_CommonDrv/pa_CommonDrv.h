//extern "C"
//{
#include "pa_Defines.h"

#ifndef __pa_CommonDrv_h__
#define __pa_CommonDrv_h__

#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"
//hasRTOS
// #define hasRTOS
/////////////////////////////////////////////////////
// #define MSP432P//select Board(选择板子)
// #define ESP32
/////////////////////////////////////////////////////////////////////
// includes //////////////////
#ifdef MSP432P
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#endif
#ifdef ESP32
#include "esp32-hal.h"
#endif
#ifdef TM4C123G
#include "driverlib/pin_map.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/ssi.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "driverlib/i2c.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

#endif
#ifdef STM32_F4
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
#endif
#ifdef STM32_H7
#include "stm32h7xx_hal.h"
#include "cmsis_os.h"
#endif

#ifdef MSP432E
#include <ti/drivers/GPIO.h>
#include <ti/drivers/SPI.h>
#include <ti/drivers/Timer.h>
// #include <ti/display/Display.h>
/* Driver configuration */
#include "ti_drivers_config.h"
/* POSIX Header files */
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#endif

    // #include pa_MEM_CUSTOM_INCLUDE l    .
    //【必须】系统配置一个100us定时器来调用
    void pa_CallBack_100us();
#ifdef __cplusplus
}
#endif

#include "../pa_HardwareSPI/pa_HardwareSPI.h"
#include "../pa_HardwareIIC/pa_HardwareIIC.h"

//common Funcs（通用函数）/////////////////////////////////////////////
void pa_CommonInit();
void pa_delayMs(unsigned int ms);
void pa_setTimerCallback(void (*CallBack_100us)(void), void (*CallBack_1ms)(void));
void pa_delayUs(unsigned int us);

uint64_t pa_millis();

void pa_printf(const char *format, ...);
void pa_Debug(const char *data);
void pa_Debug_len(const char *data, int len);

#ifdef TM4C123G
uint32_t getSyscylOfGpioPort(uint32_t port);
#endif
/////////////////////////////////////////////////////////
typedef enum
{
    protocal_SPI = 1,
    protocal_IIC
} Protocal;

typedef enum
{
    gpioInputMode_pullup = 1,
    gpioInputMode_pulldown,
    gpioInputMode_hang,
} GpioInputMode;

typedef enum
{
    direction_increase = 1,
    direction_decrease = 0,
} Direction;

#endif
