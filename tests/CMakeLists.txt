add_executable(FastDb_tests
    placeholder_test.cpp
    # Add test files here as you create them, e.g.:
    # page_test.cpp
)

target_link_libraries(FastDb_tests PRIVATE fastdb_core Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(FastDb_tests)
