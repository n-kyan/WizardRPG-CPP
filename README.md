# WizardRPG-CPP

*Claude was used to write this README.MD*
*Claude was used as a peer reviewer during the programming process, however all code was written by me*

A terminal-based classic RPG style wizard combat game built in modern C++20, featuring object-oriented design principles and advanced C++ concepts. Players select from three wizard schools (Life, Death, Balance) and engage in turn-based strategic combat.

## 🔧 Technical Highlights

- **Modern C++20**: Leverages concepts, smart pointers, and RAII principles
- **Polymorphic Design**: Abstract base classes with virtual functions for extensible move and wizard systems
- **Memory Safety**: Exclusive use of `std::unique_ptr` and move semantics
- **Template Programming**: SFINAE-ready template functions for type-safe input validation
- **Cross-Platform Compilation**: Optimized builds for x86 and ARM architectures

### Core C++ Concepts Demonstrated

- **Smart Pointers**: `unique_ptr` for automatic memory management
- **Move Semantics**: Efficient resource transfer in constructors
- **Polymorphism**: Virtual inheritance for wizard schools and combat moves
- **Template Metaprogramming**: Type-safe input validation with `std::is_integral_v`
- **Efficient Data Types**: Properly size integral types used at all times to reduce unnecessary space.
- **RAII**: Resource management through constructor/destructor patterns
- **Modern STL**: `std::array`, `std::random_device`, `std::uniform_int_distribution`

## 🚀 Quick Start

### Prerequisites
- C++20 compatible compiler
- Make utility (for Makefile)

### Building & Running

```bash
# Clone repository
git clone https://github.com/n-kyan/WizardRPG-CPP.git
cd WizardRPG-CPP

# Build and run
make run

# Debug build with symbols
make debug-run

# Clean build artifacts
make clean
```

### Alternative Compilation

```bash
# Manual compilation
g++ -std=c++20 -O2 -Wall -Wextra -march=native $(find . -name "*.cpp") -o WizardRPG-CPP

# Run
./WizardRPG-CPP
```

## 🎯 Gameplay

### Wizard Schools

| School | Health | Passive Ability | Strategy |
|--------|--------|----------------|----------|
| **Life** | 120 HP | +5 HP/turn | Sustained combat, healing |
| **Death** | 120 HP | +5% accuracy/turn | High damage, precision strikes |
| **Balance** | 100 HP | +3 HP & +3% accuracy/turn | Versatile, utility moves |

### Combat System

- **Turn-based combat** with pip resource management
- **Accuracy system** with multiplicative bonuses
- **Strategic depth** through resource allocation and move timing
- **RNG mechanics** using thread-local random number generation

## 📁 Project Structure

```
WizardRPG-CPP/
├── main.cpp                    # Entry point and game initialization
├── Battle.{h,cpp}             # Combat logic and turn management
├── Wizards/                   # Character classes and factories
│   ├── Wizard.{h,cpp}        # Abstract base class
│   ├── Wizard_Life.cpp       # Life school implementation
│   ├── Wizard_Death.cpp      # Death school implementation
│   └── Wizard_Balance.cpp    # Balance school implementation
├── Moves/                     # Combat abilities
│   ├── Move.{h,cpp}          # Abstract move interface
│   ├── Life/                 # Life school moves
│   ├── Death/                # Death school moves
│   ├── Balance/              # Balance school moves
│   └── All/                  # Universal moves
├── SpecialPrinter.{h,cpp}    # Terminal formatting and colors
├── utils.h                   # Template utilities and input validation
└── Makefile                  # Build configuration
```

## 🛠 Build Configuration

The Makefile supports multiple build targets optimized for different use cases:

```bash
make run          # Optimized build and execute
make debug        # Debug build with symbols
make debug-lldb   # Debug with LLDB integration
make clean        # Remove build artifacts
# Future implementation goal:
make wasm         # WebAssembly compilation 
```

### Compiler Flags
- `-std=c++20`: I thought this was a good balance of being new enough to be considered "modern c++" without getting too experimental.
- `-O2`: Performance optimization compiler flag(Alternatives:
    O0 - No optimization.
    O1 - Optimize for speed while avoiding code size increase. (Good for large code bases without heavy loop use).
    O2 - Enables vectorization (process mutiple values at the same time) and inlining of intrinsics (function calls to certain compiler recognized functions are replace with optomized assembly).
    O3 - Enables more aggressive loop transformations. Only consistently out performs O2 with loop heavy apps, lots of floating point calculations or/and large data sets. (Probably common with quant work.)
    Ofast - sets -O3 -no-prec-div -fp-model fast=2 flags
    More info - https://www.intel.com/content/www/us/en/docs/cpp-compiler/developer-guide-reference/2021-9/o-001.html
    )
- `-march=native`: CPU-specific optimizations
- `-Wall -Wextra`: Comprehensive warnings

## 🔬 Code Quality Features

### Memory Management
```cpp
// RAII and move semantics example
Battle::Battle(unique_ptr<Wizard> wizard1, unique_ptr<Wizard> wizard2) :
    w1(std::move(wizard1)),
    w2(std::move(wizard2)) {}
```

### Type Safety
```cpp
// Template-based input validation
template<typename T>
T inputValid_uint(const std::string& prompt, T minValue, T maxValue) {
    static_assert(std::is_integral_v<T>, "T must be an integral type");
    // Implementation ensures type safety at compile time
}
```

### Thread-Safe RNG
```cpp
bool Move::rollOdds(uint8_t finalAccuracy) {
    static thread_local mt19937 gen{random_device{}()};
    uniform_int_distribution<int> dist(1, 100);
    return dist(gen) <= finalAccuracy;
}
```

## 🚧 Future Enhancements

- [ ] **WebAssembly Port**: Browser-playable version using Emscripten
- [ ] **AI Opponents**: Minimax algorithm for computer players
- [ ] **Network Multiplayer**: TCP/UDP implementation for remote play
- [ ] **Save System**: JSON-based game state persistence
- [ ] **Extended Combat**: Additional schools and move combinations

## 💻 Development Notes

This project was developed as a practical exploration of advanced C++ concepts relevant to quantitative development, including:

- **Performance-oriented design** with minimal runtime overhead
- **Financial software patterns** like factory methods and strategy patterns
- **Risk management principles** through robust error handling
- **Algorithmic thinking** in game balance and probability systems

The codebase emphasizes production-quality practices suitable for quantitative finance development.

## 📊 Performance Metrics (Claude estimations)

- **Compilation time**: ~2-3 seconds on modern hardware
- **Binary size**: ~45KB (optimized release build)
- **Memory footprint**: <1MB runtime allocation
- **Platform support**: macOS (ARM64/x64), Linux (x64), Windows (MSVC)


*Built with modern C++20 • Optimized for performance • Designed for extensibility*