cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME cmd-txtreplace)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(headers)

add_executable(${PROJECT_NAME}
    main.cpp
    src/Processor.cpp
)

# Link libraries (if any)
# target_link_libraries(${PROJECT_NAME} <library_name>)