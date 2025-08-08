/* Copyright (c) 2016 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */
#ifndef CUSTOM_BOARD_H // This is intentionally using CUSTOM_BOARD_H as in custom_board.h
#define CUSTOM_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nrf_gpio.h"

#define NRF_CLOCK_LFCLKSRC {.source        = NRF_CLOCK_LF_SRC_XTAL,            \
                            .rc_ctiv       = 0,                             \
                            .rc_temp_ctiv  = 0,                              \
                            .xtal_accuracy = NRF_CLOCK_LF_XTAL_ACCURACY_20_PPM}

// LEDs definitions
#define LEDS_NUMBER     1

#define LED_0           1
#define BSP_LED_0       LED_0

#define LEDS_ACTIVE_STATE 0

#define LEDS_LIST       { LED_0 }

#define LEDS_INV_MASK   LEDS_MASK

#define BUTTONS_NUMBER  1

#define BUTTON_0        22
#define BSP_BUTTON_0    BUTTON_0

#define BUTTON_PULL     NRF_GPIO_PIN_PULLUP

#define BUTTONS_ACTIVE_STATE 0

#define BUTTONS_LIST    { BUTTON_0 }

#define CTS_PIN_NUMBER  UART_PIN_DISCONNECTED
#define RTS_PIN_NUMBER  UART_PIN_DISCONNECTED
#define HWFC            false

#define SPIM0_SCK_PIN   28     /**< SPI clock GPIO pin number. */
#define SPIM0_MOSI_PIN  25     /**< SPI Master Out Slave In GPIO pin number. */
#define SPIM0_MISO_PIN  24     /**< SPI Master In Slave Out GPIO pin number. */

#define LIS2DH12_INT1   29     /**< INT1 GPIO pin number */
#define LIS2DH12_INT2   30     /**< INT2 GPIO pin number */
#define LIS2DH12_CS     25     /**< SPI Slave Select GPIO pin number. */

#ifdef __cplusplus
}
#endif

#endif // CUSTOM_BOARD_H
