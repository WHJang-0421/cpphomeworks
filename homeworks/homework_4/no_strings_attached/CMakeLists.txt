cmake_minimum_required(VERSION 3.17) 
project(no_strings_attached
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "A string manipulation library")

add_library(cxx_settings INTERFACE)
target_compile_options(cxx_settings INTERFACE -Wall -Wextra -Wpedantic -Werror)
target_compile_features(cxx_settings INTERFACE cxx_std_17)
target_include_directories(cxx_settings INTERFACE ${PROJECT_SOURCE_DIR})

include(CTest)

add_subdirectory(external)
add_subdirectory(${PROJECT_NAME})
add_subdirectory(examples)
