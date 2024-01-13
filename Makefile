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

# Debian package name
PACKAGE_NAME = alxauto
# Version
VERSION = 0.1

# Wildcard to collect all source files in the source directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Wildcard to collect all test files in the tests directory
TEST_FILES = $(wildcard $(TESTS_DIR)/*.c)

# Create the build directory
$(shell mkdir -p $(BUILD_DIR))

# Target to build alxauto
$(BUILD_DIR)/alxauto: $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Target to build and run tests
test: $(BUILD_DIR)/tests_obj
	./$<

# Target to build tests object
$(BUILD_DIR)/tests_obj: $(TEST_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Target to create Debian package
package: $(BUILD_DIR)/alxauto
	mkdir -p $(PACKAGE_NAME)/DEBIAN
	echo "Package: $(PACKAGE_NAME)" > $(PACKAGE_NAME)/DEBIAN/control
	echo "Version: $(VERSION)" >> $(PACKAGE_NAME)/DEBIAN/control
	echo "Architecture: all" >> $(PACKAGE_NAME)/DEBIAN/control
	echo "Maintainer: Ahed Eisa <begreat5333@gmail.com>" >> $(PACKAGE_NAME)/DEBIAN/control
	echo "Description: Auto copy function prototypes from c file into a header file 
Usage: %s -D <directory_path> -H <header_file_path>\n " >> $(PACKAGE_NAME)/DEBIAN/control
	mkdir -p $(PACKAGE_NAME)/usr/bin
	cp $(BUILD_DIR)/alxauto $(PACKAGE_NAME)/usr/bin/
	dpkg-deb --build $(PACKAGE_NAME)
	mv $(PACKAGE_NAME).deb pack/
	rm -rf $(PACKAGE_NAME)

# Target to clean up generated files
clean:
	rm -f $(BUILD_DIR)/*
