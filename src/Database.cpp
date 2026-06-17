//
// Created by koellman on 17.06.26.
//

#include "fastdb/Database.hpp"

#include <fcntl.h>
#include <stdexcept>
#include <unistd.h>
#include <sys/stat.h>

#include "fastdb/Constants.hpp"
#include "fastdb/EndianSerializer.hpp"
#include "fastdb/Page.hpp"
#include "fastdb/Page0.hpp"


Database::Database(const std::string& file_name) {
    fd_ = open(file_name.c_str(), O_RDWR | O_CREAT, 0644);
    if (fd_ == -1) {
        throw std::runtime_error("Failed to open database file: " + file_name);
    }
    struct stat stat{};
    if (fstat(fd_, &stat) == -1) {
        throw std::runtime_error("Failed to open database file: " + file_name);
    }
    is_new_ = stat.st_size == 0;
    if (is_new_) {
        create_page0();
        return;
    }
    //Read Page 0
    //Set class vars
}

void Database::create_page0() {
    Page0 header{
        .magic_number      = fastdb::MAGIC_NUMBER,
        .version_major     = 1,
        .version_minor     = 0,
        .page_size         = fastdb::PAGE_SIZE,
        .sys_tables_page   = 1,
        .sys_columns_page  = 2,
        .free_space_map_page = 3,
        .page_count        = 4
    };
    Page page(0);

    fastdb::serializer::write_uint64(page.buffer_.data(), 0, header.magic_number);
    fastdb::serializer::write_uint16(page.buffer_.data(), 8, header.version_major);
    fastdb::serializer::write_uint16(page.buffer_.data(), 10, header.version_minor);
    fastdb::serializer::write_uint64(page.buffer_.data(), 12, header.page_size);
    fastdb::serializer::write_uint32(page.buffer_.data(), 20, header.sys_tables_page);
    fastdb::serializer::write_uint32(page.buffer_.data(), 24, header.sys_columns_page);
    fastdb::serializer::write_uint32(page.buffer_.data(), 28, header.free_space_map_page);
    fastdb::serializer::write_uint64(page.buffer_.data(), 32, header.page_count);

    ssize_t result = write(fd_, page.buffer_.data(), fastdb::PAGE_SIZE);
    if (result != fastdb::PAGE_SIZE) {
        throw std::runtime_error("Failed to write page 0");
    }
}
