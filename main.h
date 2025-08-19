#pragma once
// clang-format off

#include "nrf5x-compat.h"
#include "ble_stack.h"
#include "lis2dh12.h"

#ifndef RANDOM_ROTATE_KEYS
#define RANDOM_ROTATE_KEYS 1
#endif

#ifndef MAX_KEYS
// Maximum number of public keys to rotate
// Can be set during compilation with make MAX_KEYS=10
#define MAX_KEYS 50
#endif

#ifndef KEY_ROTATION_INTERVAL
// Key rotation interval in seconds
#define KEY_ROTATION_INTERVAL 3600 * 3
#endif

#if NRF_SDK_VERSION < 15
    #define PRESCALER_VALUE APP_TIMER_PRESCALER
#else
    #define PRESCALER_VALUE APP_TIMER_CONFIG_RTC_FREQUENCY
#endif

static constexpr float RTC_FREQUENCY = (32768 / (PRESCALER_VALUE + 1));

// Maximum number of ticks (24-bit counter)
static constexpr uint32_t MAX_RTC_TICKS = 0xFFFFFF;

// Maximum time before overflow, in seconds
static constexpr float MAX_TIMER_INTERVAL_SECONDS = (MAX_RTC_TICKS / RTC_FREQUENCY);

// Force computation of values using macros
static constexpr float COMPUTED_RTC_FREQUENCY = RTC_FREQUENCY;
static constexpr float COMPUTED_MAX_TIMER_INTERVAL = MAX_TIMER_INTERVAL_SECONDS;

// Static assert to ensure that the key rotation interval fits within the max timer interval
static_assert(KEY_ROTATION_INTERVAL <= COMPUTED_MAX_TIMER_INTERVAL, "KEY_ROTATION_INTERVAL exceeds max timer interval for the configured RTC frequency.");
