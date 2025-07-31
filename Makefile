# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++20 -O2 -Wall -Wextra -march=native

# Target Executable
TARGET = main

# Source files
SOURCES = $(shell find . -name "*.cpp")

# Object files (replaces .cpp with .o)
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Convenience targets
run: $(TARGET)
	./$(TARGET)

run-auto: $(TARGET)
	clear && echo -e "2" | ./$(TARGET)

clean:
	find . -name "*.o" -delete
	rm -f $(TARGET)

# Debug target with debug symbols
debug: CXXFLAGS += -g -DDEBUG
debug: $(TARGET)

debug-files:
	@echo "Source files found:"
	@find . -name "*.cpp"
	@echo ""
	@echo "Object files that will be created:"
	@find . -name "*.cpp" | sed 's/\.cpp/\.o/'

debug-run: debug
	@echo "Starting LLDB with automatic breakpoint at main..."
	@echo "Additional useful commands:"
	@echo "  n (next line)"
	@echo "  s (step into)"
	@echo "  c (continue)"
	@echo "  p variable_name (print variable)"
	@echo "  quit (exit debugger)"
	@echo ""
	lldb -o "b main" -o "run" ./$(TARGET)

# Alternative: Start LLDB but don't auto-run (for manual control)
debug-lldb: debug
	@echo "Starting LLDB. Type 'b main' then 'run' to begin debugging."
	lldb ./$(TARGET)

# Start with multiple breakpoints
debug-battle: debug
	@echo "Starting LLDB with breakpoints for battle debugging..."
	lldb -o "b main" -o "b Battle::playRound" -o "b createWizard" -o "run" ./$(TARGET)

# WASM
EMCC = emcc
EMCFLAGS = -std=c++20 -O2 -s WASM=1 -s USE_SDL=0 --bind

# Find all source files (same as before)
SOURCES = $(shell find . -name "*.cpp")

# WASM target
wasm: 
	$(EMCC) $(EMCFLAGS) $(SOURCES) -o wizard-battle.html \
		-s EXPORTED_FUNCTIONS='["_main"]' \
		-s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
		--shell-file shell.html

# Simple WASM without custom shell
wasm-simple:
	$(EMCC) $(EMCFLAGS) $(SOURCES) -o wizard-battle.html



.PHONY: run clean debug debug-files debug-run debug-lldb debug-battle wasm wasm-simple