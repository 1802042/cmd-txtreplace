cmake_minimum_required(VERSION 3.10)

# Set the project name
project(cmd-txtreplace-tests)

# Enable testing
enable_testing()

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add test source files
add_executable(cmd-txtreplace-tests
    main.cpp
    outputFileTest.cpp
    ../src/Processor.cpp
    ../src/ProcessorFactory.cpp
)

# Link GoogleTest to the test executable
target_link_libraries(
  cmd-txtreplace-tests
  gtest_main
)

# Discover tests
include(GoogleTest)
gtest_discover_tests(cmd-txtreplace-tests)