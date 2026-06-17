//
// Created by koellman on 17.06.26.
//

#ifndef FASTDB_DATABASE_HPP
#define FASTDB_DATABASE_HPP
#include <cstdint>
#include <string>


class Database {
public:
    Database(const std::string& file_name);
private:
    int fd_;
    bool is_new_;

    void create_page0();
};

#endif //FASTDB_DATABASE_HPP
