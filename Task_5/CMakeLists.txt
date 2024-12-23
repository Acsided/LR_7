cmake_minimum_required(VERSION 3.22)
project("Task_5")

set(CLANG_TIDY_COMMAND "/usr/bin/clang-tidy")
set(CLANG_TIDY_CHECKS "readability-*,modernize-*")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer") #-fsanitize=thread

add_custom_target(
    linterT5
    COMMAND ${CLANG_TIDY_COMMAND} --checks=${CLANG_TIDY_CHECKS} --format-style=file ${CMAKE_SOURCE_DIR}/Task_5/*.cpp
    COMMENT "RUNNING CLANG_TIDY" 
)

add_executable(Task5 Task_5.cpp)

add_dependencies(Task5 linterT5)
