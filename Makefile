CC = gcc
CFLAGS = -Iinclude -Wall $(shell pkg-config --cflags glib-2.0)
LDFLAGS = $(shell pkg-config --libs glib-2.0)
DEPS = include/longest_common_substring.h
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/longest_common_substring.o
BIN = $(BIN_DIR)/main

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN): $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(BIN)