# Setup & Execution Guide

Application can be set up in any of two ways:
---

## 1. Quick Start (Easy): 
If you want to run the simulator immediately without installing a compiler, CMake, or other build tools:

1. Go to the [Releases](https://github.com/abir-0X/Elevator-Project-OOPS/releases) page.
2. Download the ZIP file corresponding to your operating system:
   - `elevator_sim-windows.zip` (for Windows)
   - `elevator_sim-macos.zip` (for macOS)
   - `elevator_sim-linux.zip` (for Linux)
3. Extract the contents of the ZIP file.
4. Run the executable:
---

## 2. Local Setup Guide (Build from Source)

Follow these steps to set up and run the simulator from source on your local machine.

## Prerequisites

Ensure you have the following installed on your system:
- **CMake**: Version 3.15 or higher (Verify with `cmake --version`)
- **C++ Compiler**: A compiler supporting C++17 (e.g., MSVC on Windows, GCC/Clang on macOS/Linux)
- **Git**: (Verify with `git --version`)

## Steps to Build

1. **Clone the Repository**
   ```bash
   git clone <repository_url>
   cd OOPS-LLD-ELEVATOR
   ```

2. **Navigate to Project Directory**
   ```bash
   cd SmartElevatorSystem
   ```

3. **Configure the Project**
   Create a build directory and configure the project:
   ```bash
   cmake -B build
   ```

4. **Compile and Build**
   Build the executable and library targets:
   ```bash
   cmake --build build
   ```

5. **Run the Simulation**
   Execute the compiled binary:
   - **Windows (MinGW/GCC)**:
     ```powershell
     .\build\elevator_sim.exe
     ```
   - **macOS/Linux**:
     ```bash
     ./build/elevator_sim
     ```
