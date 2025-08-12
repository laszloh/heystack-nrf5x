#pragma once

#include <stdint.h>
#include <stdbool.h>

bool accelerometer_init(void);

typedef struct{
    uint16_t x;
    uint16_t y;
    uint16_t z;
} data_t;

data_t accelerometer_read();
