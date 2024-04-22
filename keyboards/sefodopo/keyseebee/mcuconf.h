#ifndef KEYSEEBEE_MCUCONF_H
#define KEYSEEBEE_MCUCONF_H

#include_next <mcuconf.h>

#undef STM32_SERIAL_USE_USART1
#define STM32_SERIAL_USE_USART1 TRUE

#endif
