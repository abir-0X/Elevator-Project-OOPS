cmake_minimum_required(VERSION 3.15)
project(SmartElevatorSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(-U__STRICT_ANSI__)
    if(WIN32)
        add_compile_definitions(GTEST_OS_WINDOWS_PHONE=1 GTEST_HAS_FILE_SYSTEM=0)
    endif()
endif()



# Define include directories
include_directories(include)

# Source files for the elevator library
set(LIB_SOURCES
    src/Elevator.cpp
    src/Floor.cpp
    src/Request.cpp
    src/Building.cpp
    src/Display.cpp
    src/Scheduler.cpp
    src/NearestScanScheduler.cpp
)

# Compile library
if(LIB_SOURCES)
    add_library(elevator_lib STATIC ${LIB_SOURCES})
    target_include_directories(elevator_lib PUBLIC include)
endif()

# Main executable
add_executable(elevator_sim src/main.cpp)
if(LIB_SOURCES)
    target_link_libraries(elevator_sim PRIVATE elevator_lib)
endif()

# Testing configuration
option(BUILD_TESTING "Build unit tests" ON)
if(BUILD_TESTING)
    include(FetchContent)
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    # Prevent overriding parent compiler settings on Windows
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    add_executable(elevator_tests
        tests/test_elevator.cpp
        tests/test_scheduler.cpp
        tests/test_validation.cpp
    )
    target_link_libraries(elevator_tests PRIVATE elevator_lib gtest_main)
    target_include_directories(elevator_tests PRIVATE include)

    add_test(NAME elevator_unit_tests COMMAND elevator_tests)
endif()
