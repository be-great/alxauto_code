# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -I/usr/include

# Linker flags
LDFLAGS = -shared

# Source directory
SRC_DIR = src

# Tests directory
TESTS_DIR = tests

# Build directory
BUILD_DIR = build


# Wildcard to collect all source files in the source directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Wildcard to collect all test files in the tests directory
TEST_FILES = $(wildcard $(TESTS_DIR)/*.c)

alxauto:
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/alxauto $(SRC_FILES)

# Target to build and run tests
test:
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/tests_obj $(TEST_FILES)
	./$(BUILD_DIR)/tests_obj


# Target to clean up generated files
clean:
	rm -f $(BUILD_DIR)/*
