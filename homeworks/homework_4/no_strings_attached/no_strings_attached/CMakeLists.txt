add_library(string_split string_split.cpp)
target_link_libraries(string_split PUBLIC cxx_settings)

add_library(string_trim string_trim.cpp)
target_link_libraries(string_trim PUBLIC cxx_settings)

if (BUILD_TESTING)
    include(GoogleTest)

    add_executable(string_split_test string_split_test.cpp)
    target_link_libraries(string_split_test PRIVATE cxx_settings string_split GTest::gtest_main)
    gtest_discover_tests(string_split_test)

    add_executable(string_trim_test string_trim_test.cpp)
    target_link_libraries(string_trim_test PRIVATE cxx_settings string_trim GTest::gtest_main)
    gtest_discover_tests(string_trim_test)
endif()
