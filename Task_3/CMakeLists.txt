cmake_minimum_required(VERSION 3.22)
project("Task_3")

set(CLANG_TIDY_COMMAND "/usr/bin/clang-tidy")
set(CLANG_TIDY_CHECKS "readability-*,modernize-*")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer") #-fsanitize=thread

add_custom_target(
    linterT3
    COMMAND ${CLANG_TIDY_COMMAND} --checks=${CLANG_TIDY_CHECKS} --format-style=file ${CMAKE_SOURCE_DIR}/Task_3/*.cpp
    COMMENT "RUNNING CLANG_TIDY" 
)

add_executable(Task3 Task_3.cpp)

add_dependencies(Task3 linterT3)
