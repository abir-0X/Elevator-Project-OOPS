# Smart Elevator System Simulator

A console-based simulator of a multi-floor, multi-elevator system in C++17. Designed with Low-Level Design (LLD) practices, SOLID principles, and clean C++ architecture.

---

## Key Highlights & Architectural Features

### SOLID Low-Level Design (LLD)
- **Single Responsibility (SRP)**: Clean separation between elevator states, requests routing, building container lifecycle, UI display, and dispatcher scheduler.
- **Open-Closed (OCP) & Dependency Inversion (DIP)**: Pluggable scheduling algorithm interface (`ISchedulingAlgorithm`) allowing new routing strategies to be swapped transparently without modifying the `Scheduler` orchestrator.
- **Interface Segregation (ISP) & Liskov Substitution (LSP)**: Strategy patterns and decoupled class designs prevent interface pollution and ensure safe subclass substitution.

### Design Patterns
- **Strategy Pattern**: The central `Scheduler` delegates assignment calculations polymorphically to concrete algorithm subclasses (like the `NearestScanScheduler`).
- **Composition & Aggregation**:
  - `Building` owns (Composition) collections of `Floor` and `Elevator` objects.
  - `Elevator` tracks and processes (Aggregation) temporary list of `Request` records.

### Nearest-Elevator SCAN Cost Routing Strategy
The scheduling strategy evaluates floor calls using a proximity cost algorithm with directional alignment rewards:
- **Idle Elevator**: Cost is simply the absolute distance: $\text{cost} = | \text{current\_floor} - \text{source\_floor} |$.
- **Moving Elevator (Aligned)**: If the elevator is moving UP and the floor request is above it in the UP direction, cost is just the distance. Similarly for DOWN direction.
- **Moving Elevator (Misaligned)**: If the request is in the opposite direction or behind the current position, a standard misalignment penalty ($+100$) is added to prevent sudden direction shifts, maintaining the SCAN movement pattern.

---

## Folder Structure

```text
OOPS-LLD-ELEVATOR/
├── SmartElevatorSystem/      # Main C++ Project Directory
│   ├── include/              # Header declarations (.h)
│   ├── src/                  # Implementation sources (.cpp)
│   └── CMakeLists.txt        # CMake configuration build file
├── README.md                 # Project Overview Portfolio (This file)
|── setup.md                  # Project Local Installation Guide
```

---

## Features Implemented

- Multi-elevator, multi-floor support.
- External floor buttons (Up/Down) & internal destination buttons.
- State-based elevator movement logic.
- Optimized nearest-elevator dispatch scheduling.
- Google Test automated test coverage.
- Structured comments using the STAR method.
