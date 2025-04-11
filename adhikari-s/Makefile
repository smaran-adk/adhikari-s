CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -O2
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin

SRC = $(SRC_DIR)/cryptoMagic.c $(SRC_DIR)/cryptoUtils.c $(SRC_DIR)/file_utils.c
OBJ = $(SRC:.c=.o)
TARGET = $(BIN_DIR)/cryptoMagic

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/cryptoMagic.h $(INCLUDE_DIR)/file_utils.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
