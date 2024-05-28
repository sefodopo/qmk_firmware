#ifndef KEYSEEBEE_MCUCONF_H
#define KEYSEEBEE_MCUCONF_H

#include_next <mcuconf.h>

#undef STM32_SERIAL_USE_USART1
#define STM32_SERIAL_USE_USART1 TRUE
#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE
// Can't get the DMA working for I2C :(
#undef STM32_I2C_USE_DMA
#define STM32_I2C_USE_DMA FALSE
// #undef STM32_I2C_I2C1_DMA_PRIORITY
// #define STM32_I2C_I2C1_DMA_PRIORITY 2
// #undef STM32_I2C_BUSY_TIMEOUT
// #define STM32_I2C_BUSY_TIMEOUT 1000

#endif
