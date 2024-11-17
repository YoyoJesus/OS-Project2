# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# File names
TARGET = bankers
OBJ_FILES = bankers_main.o bankers_math.o

# Default target to compile the program
all: $(TARGET)

# Compile the main program
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)

# Compile the main file
bankers_main.o: bankers_main.cpp bankers.hpp
	$(CXX) $(CXXFLAGS) -c bankers_main.cpp

# Compile the math file
bankers_math.o: bankers_math.cpp bankers.hpp
	$(CXX) $(CXXFLAGS) -c bankers_math.cpp

# Clean up the compiled files
clean:
	rm -f $(TARGET) $(OBJ_FILES)

# Run the program (optional)
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
