# C++ Data Structures & Algorithm Benchmarks

A collection of high-performance, memory-safe C++ implementations focusing on low-level data structures, dynamic memory management, and algorithmic efficiency.

## Features
- Explicit memory management using raw pointers, dynamic allocation (`new`/`delete`), and custom destructors.
- Edge-case handling for null pointers, empty data structures, and boundary values.
- Clean C++17 modular design following modern best practices.

## Included Components
- **Dynamic Array / Vector Implementation**: Custom memory reallocation logic.
- **Benchmark Utility**: Execution time tracking using `<chrono>`.

## Tech Stack
- Language: C++17
- Compiler: GCC / Clang / MSVC
- Build System: Direct Compilation / CMake

## How to Compile & Run
```bash
# Clone repository
git clone [https://github.com/your-username/cpp-data-structures-benchmarks.git](https://github.com/your-username/cpp-data-structures-benchmarks.git)

# Navigate to directory
cd cpp-data-structures-benchmarks

# Compile
g++ -std=c++17 main.cpp -o benchmark

# Execute
./benchmark
