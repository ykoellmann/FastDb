#pragma once
#include <cstdint>

namespace fastdb {
    constexpr uint64_t MAGIC_NUMBER =
    static_cast<uint64_t>('F') << 56 |
    static_cast<uint64_t>('A') << 48 |
    static_cast<uint64_t>('S') << 40 |
    static_cast<uint64_t>('T') << 32 |
    static_cast<uint64_t>('D') << 24 |
    static_cast<uint64_t>('B') << 16;

    constexpr uint32_t PAGE_SIZE = 4096;
}
