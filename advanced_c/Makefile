# Makefile

# Directory structure
dir_arg := $(firstword $(MAKECMDGOALS))
SRC_DIR := $(dir_arg)/src
INCLUDE_DIR := $(dir_arg)/include
BUILD_DIR := $(dir_arg)/build

# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -I$(INCLUDE_DIR)

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.c)

# If no source files found, create main.c with a temporary "Hello, World!" code snippet
ifeq ($(SRCS),)
    $(shell mkdir -p $(SRC_DIR))
    $(shell echo '#include <stdio.h>\n\nint main() {\n    printf("Hello, World!\\n");\n    return 0;\n}' > $(SRC_DIR)/main.c)
    SRCS := $(SRC_DIR)/main.c
endif

# Object files
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Executable
TARGET := $(BUILD_DIR)/$(firstword $(MAKECMDGOALS))

.PHONY: all clean run $(MAKECMDGOALS)

all: $(TARGET)

# Create directories if not exist
$(shell mkdir -p $(SRC_DIR) $(INCLUDE_DIR) $(BUILD_DIR))

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	rm -rf $(OBJS)

clean:
	rm -rf $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)

%:
	@:

