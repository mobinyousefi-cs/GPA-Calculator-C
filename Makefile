# Project: GPA Calculator (C)
# Author: Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)

CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -Wpedantic -O2

SRC_DIR := src
BUILD_DIR := build
TEST_DIR := tests

SRCS := $(SRC_DIR)/main.c \
        $(SRC_DIR)/gpa_calculator.c \
        $(SRC_DIR)/grade_scale.c \
        $(SRC_DIR)/input_utils.c

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

TARGET := $(BUILD_DIR)/gpa_calculator
TEST_TARGET := $(BUILD_DIR)/test_gpa_calculator

.PHONY: all clean test run

all: $(TARGET)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

run: $(TARGET)
	$(TARGET)

# --- Tests ---

TEST_SRC := $(TEST_DIR)/test_gpa_calculator.c

$(TEST_TARGET): $(TEST_SRC) $(filter-out $(SRC_DIR)/main.c,$(SRCS)) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

test: $(TEST_TARGET)
	$(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR)
