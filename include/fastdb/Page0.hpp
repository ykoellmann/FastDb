#pragma once

#include <cstdint>

struct Page0 {
    uint64_t magic_number;
    uint16_t version_major;
    uint16_t version_minor;
    uint64_t page_size;
    uint32_t sys_tables_page;
    uint32_t sys_columns_page;
    uint32_t free_space_map_page;
    uint64_t page_count;
};
