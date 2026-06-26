cmake_minimum_required(VERSION 3.15)
project(SmartElevatorSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define include directories
include_directories(include)

# Source files for the elevator library (will be populated as we build classes)
set(LIB_SOURCES
    src/Elevator.cpp
    src/Floor.cpp
    src/Request.cpp
    src/Building.cpp
    src/Display.cpp
)

# If no sources exist yet for library, compile only executable
if(LIB_SOURCES)
    add_library(elevator_lib STATIC ${LIB_SOURCES})
    target_include_directories(elevator_lib PUBLIC include)
endif()

# Main executable
add_executable(elevator_sim src/main.cpp)
if(LIB_SOURCES)
    target_link_libraries(elevator_sim PRIVATE elevator_lib)
endif()
