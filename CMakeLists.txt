cmake_minimum_required(VERSION 3.20)
project(FastDb)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands for clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --- Core library ---
# Add source files here as you create them, e.g.:
# target_sources(fastdb_core PRIVATE src/page.cpp)
add_library(fastdb_core STATIC
    src/Database.cpp
    src/Page.cpp
        include/fastdb/Constants.hpp
)
target_include_directories(fastdb_core PUBLIC include)

# --- Main executable ---
add_executable(FastDb main.cpp
)
target_link_libraries(FastDb PRIVATE fastdb_core)

# --- Tests (Catch2) ---
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.8.1
)
FetchContent_MakeAvailable(Catch2)

enable_testing()
add_subdirectory(tests)
