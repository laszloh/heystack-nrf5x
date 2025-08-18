
#include "lis2dh12.h"
#include "lis2dh12_reg.h"

#include "boards.h"
#include "nrf_delay.h"
#include "nrf_drv_spi.h"

static int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp, uint16_t len);
static int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);
static void tx_com(uint8_t *tx_buffer, uint16_t len);
static void platform_delay(uint32_t ms);

static stmdev_ctx_t dev_ctx;
static nrf_drv_spi_t spi_ctx = NRF_DRV_SPI_INSTANCE(SPI0_INSTANCE_INDEX);
static volatile bool init = false;

bool accelerometer_init(void) {
    if(init)
        return init;

    nrf_drv_spi_config_t config = NRF_DRV_SPI_DEFAULT_CONFIG;
    config.sck_pin = SPIM0_SCK_PIN;
    config.mosi_pin = SPIM0_MOSI_PIN;
    config.miso_pin = SPIM0_MISO_PIN;
    config.ss_pin = LIS2DH12_CS;
    APP_ERROR_CHECK(nrf_drv_spi_init(&spi_ctx, &config, NULL));

    dev_ctx.write_reg = platform_write;
    dev_ctx.read_reg = platform_read;
    dev_ctx.mdelay = platform_delay;

    // wait for accelerometer boot
    nrf_delay_ms(10);

    uint8_t id;
    uint8_t ret = lis2dh12_device_id_get(&dev_ctx, &id);
    if(id != LIS2DH12_ID) {
        // accelerometer did not return expected id
        return false;
    }

    // setup accelerometer as low power fall detector
    lis2dh12_operating_mode_set(&dev_ctx, LIS2DH12_LP_8bit);
    lis2dh12_data_rate_set(&dev_ctx, LIS2DH12_ODR_25Hz);

    lis2dh12_high_pass_bandwidth_set(&dev_ctx, LIS2DH12_STRONG);

    init = true;
    return true;
}

data_t accelerometer_read() { }

int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp, uint16_t len) { return nrf_drv_spi_transfer(&spi_ctx, bufp, len, NULL, 0); }

int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len) { return nrf_drv_spi_transfer(&spi_ctx, NULL, 0, bufp, len); }

void platform_delay(uint32_t ms) { nrf_delay_ms(ms); }
