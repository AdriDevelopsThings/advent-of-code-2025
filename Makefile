INCLUDE_DIR := include
SRC_DIR := src
OBJ_DIR := obj

CC := gcc
CFLAGS := -Wall -I$(INCLUDE_DIR)
FORMATFLAGS := --style="file:.clang-format" -i

FORMAT := clang-format

SRC := $(shell find $(SRC_DIR) -name '*.c')
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

BIN := aoc

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: format
format:
	$(FORMAT) $(FORMATFLAGS) $$(find $(SRC_DIR) $(INCLUDE_DIR) -name '*.c' -o -name '*.h')
	@echo "Finished reformatting code."

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm $(BIN)
