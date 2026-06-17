//
// Created by koellman on 17.06.26.
//

#ifndef FASTDB_PAGE_HPP
#define FASTDB_PAGE_HPP
#include <cstdint>
#include <array>

#include "Constants.hpp"

class Page {
    friend class Database;
public:
    Page(int id) : id_(id) {}
    [[nodiscard]] int get_id() const;
private:
    int id_;
    std::array<uint8_t, fastdb::PAGE_SIZE> buffer_{};
};

#endif //FASTDB_PAGE_HPP
