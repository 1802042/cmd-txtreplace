cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME cmd-txtreplace)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(headers)

add_executable(${PROJECT_NAME}
    main.cpp
    src/Processor.cpp
)
