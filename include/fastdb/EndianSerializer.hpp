#pragma once
#include <cstdint>

namespace fastdb::serializer {
    inline void write_uint16(uint8_t* buffer, uint32_t offset, uint16_t value) {
        buffer[offset]     = value >> 8 & 0xFF;
        buffer[offset + 1] = value      & 0xFF;
    }

    inline void write_uint32(uint8_t* buffer, uint32_t offset, uint32_t value) {
        buffer[offset]     = value >> 24 & 0xFF;
        buffer[offset + 1] = value >> 16 & 0xFF;
        buffer[offset + 2] = value >> 8  & 0xFF;
        buffer[offset + 3] = value       & 0xFF;
    }

    inline void write_uint64(uint8_t* buffer, uint32_t offset, uint64_t value) {
        buffer[offset]     = value >> 56 & 0xFF;
        buffer[offset + 1] = value >> 48 & 0xFF;
        buffer[offset + 2] = value >> 40 & 0xFF;
        buffer[offset + 3] = value >> 32 & 0xFF;
        buffer[offset + 4] = value >> 24 & 0xFF;
        buffer[offset + 5] = value >> 16 & 0xFF;
        buffer[offset + 6] = value >> 8  & 0xFF;
        buffer[offset + 7] = value       & 0xFF;
    }

    inline uint16_t read_uint16(const uint8_t* buffer, uint32_t offset) {
        return static_cast<uint16_t>(buffer[offset])     << 8 |
               static_cast<uint16_t>(buffer[offset + 1]);
    }

    inline uint32_t read_uint32(const uint8_t* buffer, uint32_t offset) {
        return static_cast<uint32_t>(buffer[offset])     << 24 |
               static_cast<uint32_t>(buffer[offset + 1]) << 16 |
               static_cast<uint32_t>(buffer[offset + 2]) << 8  |
               static_cast<uint32_t>(buffer[offset + 3]);
    }

    inline uint64_t read_uint64(const uint8_t* buffer, uint32_t offset) {
        return static_cast<uint64_t>(buffer[offset])     << 56 |
               static_cast<uint64_t>(buffer[offset + 1]) << 48 |
               static_cast<uint64_t>(buffer[offset + 2]) << 40 |
               static_cast<uint64_t>(buffer[offset + 3]) << 32 |
               static_cast<uint64_t>(buffer[offset + 4]) << 24 |
               static_cast<uint64_t>(buffer[offset + 5]) << 16 |
               static_cast<uint64_t>(buffer[offset + 6]) << 8 |
               static_cast<uint64_t>(buffer[offset + 7]);
    }
}
