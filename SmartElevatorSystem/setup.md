# Local Setup Guide

Follow these steps to set up, build, and run the Smart Elevator System Simulator on your local machine.

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
   - **Windows (CMD/PowerShell)**:
     ```powershell
     .\build\Debug\elevator_sim.exe
     ```
   - **macOS/Linux**:
     ```bash
     ./build/elevator_sim
     ```

## Running Tests

Once testing is integrated (using Google Test):
```bash
cd build
ctest --output-on-failure
```
