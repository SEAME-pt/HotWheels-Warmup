# Makefile for compiling the project with CMake

# Define the build directory and executable name
BUILD_DIR = build
EXECUTABLE = main
TEST_SCRIPT = tests/test_phonebook.sh

# Default target
all: $(BUILD_DIR)/$(EXECUTABLE)

# Create the build directory and generate the build files using CMake
$(BUILD_DIR)/$(EXECUTABLE): 
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake .. && make

# Run the executable
run: all
	@./$(BUILD_DIR)/$(EXECUTABLE)

# Run tests using the test script
test: all
	@bash $(TEST_SCRIPT)

# Clean the build directory
clean:
	@rm -rf $(BUILD_DIR)

# Rebuild the project from scratch
re: clean all

# Phony targets
.PHONY: all run clean test re
