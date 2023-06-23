cmake_minimum_required(VERSION 3.16)
project(hello)
set(CMAKE_CXX_STANDARD 17)
add_executable(hello
    src/main.cpp
    include/image_dos_header.h
    src/image_dos_header.cpp
    include/image_file_header.h
    src/image_file_header.cpp
    include/image_optional_header32.h
    src/image_optional_header32.cpp
    include/utils.h
    src/utils.cpp
)
target_include_directories(hello PUBLIC include)
