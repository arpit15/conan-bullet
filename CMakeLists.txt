project(cmake_wrapper)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-c++11-narrowing")

add_subdirectory("source_subfolder")
