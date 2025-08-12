
#include <stdint.h>

#include "lis2dh12.h"
#include "lis2dh12_reg.h"

#include "boards.h"
#include "nrf_drv_spi.h"

static int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp, uint16_t len);
static int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);
static void tx_com(uint8_t *tx_buffer, uint16_t len);
static void platform_delay(uint32_t ms);

bool accelerometer_init(void) {
    nrf_drv_spi_t instance = NRF_DRV_SPI_INSTANCE(SPI0_INSTANCE_INDEX);
    nrf_drv_spi_config_t config =NRF_DRV_SPI_DEFAULT_CONFIG;
    config.sck_pin = SPIM0_SCK_PIN;
    config.mosi_pin = SPIM0_MOSI_PIN;
    config.miso_pin = SPIM0_MISO_PIN;
    config.ss_pin = LIS2DH12_CS;
    APP_ERROR_CHECK(nrf_drv_spi_init(&instance, &config, NULL));
}

data_t accelerometer_read() {
    
}

int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp, uint16_t len) {

}

int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len) {

}

void tx_com(uint8_t *tx_buffer, uint16_t len) {

}

void platform_delay(uint32_t ms) {
    
}
