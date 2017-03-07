cmake_minimum_required(VERSION 3.6)
project(fillit)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        alloc_wrap.c
        fillit.h
        libft.h
        read.c
        split.c
        valid.c)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
add_subdirectory(libft)

add_executable(fillit ${SOURCE_FILES})
target_link_libraries(fillit PUBLIC libft)
add_test(examples/error_0 fillit)
