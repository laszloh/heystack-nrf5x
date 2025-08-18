#pragma once

#ifndef DATA_T
#error "DATA_T must be defined"
#endif

#define RAM_MEMORY_VALIDITY_WORD    (0xFEEDBEEFUL)
#define RESET_MEMORY_TEST_BYTE      (0xAF)

#include <stdlib.h> // realloc, size_t
#include <stdint.h>

typedef struct {
    uint32_t validity;
    uint32_t crc;
    DATA_T data;
} container_t;


