#pragma once

#include <cstdint>

template <typename T> class RamRetetion {
public:
    RamRetetion() = default;

    bool validate() const {
        if(marker != validityWord)
            return false;
        return crc == calcCrc();
    }
    explicit operator bool() const { return validate(); }

    void reset() { marker = 0x00; }

    T &get() { return data; }
    const T &get() const { return data; }

    void set(const T &d) {
        marker = validityWord;
        data = d;
        crc = calcCrc();
    }
    void recompute() { set(data); }

protected:
    static constexpr uint32_t validityWord = 0xFEEDBEEF;

    uint32_t crc32(uint8_t const *p_data, uint32_t size, uint32_t const *p_crc) const {
        uint32_t crc;

        crc = (p_crc == NULL) ? 0xFFFFFFFF : ~(*p_crc);
        for(uint32_t i = 0; i < size; i++) {
            crc = crc ^ p_data[i];
            for(uint32_t j = 8; j > 0; j--) {
                crc = (crc >> 1) ^ (0xEDB88320U & ((crc & 1) ? 0xFFFFFFFF : 0));
            }
        }
        return ~crc;
    }

    uint32_t calcCrc() const {
        uint32_t res;
        res = crc32((const uint8_t *)&marker, sizeof(marker), NULL);
        return crc32((const uint8_t *)&data, sizeof(T), &res);
    }

    uint32_t marker;
    uint32_t crc;
    T data;
};
