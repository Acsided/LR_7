cmake_minimum_required(VERSION 3.22)
project("Task_4")

set(CLANG_TIDY_COMMAND "/usr/bin/clang-tidy")
set(CLANG_TIDY_CHECKS "readability-*,modernize-*")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer") #-fsanitize=thread

add_custom_target(
    linterT4
    COMMAND ${CLANG_TIDY_COMMAND} --checks=${CLANG_TIDY_CHECKS} --format-style=file ${CMAKE_SOURCE_DIR}/Task_4/*.cpp
    COMMENT "RUNNING CLANG_TIDY" 
)

add_executable(Task4 Task_4.cpp)

add_dependencies(Task4 linterT4)
