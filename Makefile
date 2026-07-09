# Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99 -Wextra

# Executable name
TARGET = book-tracker-v1

# Source and object files
SRC = src/book.c src/fileio.c src/main.c src/menu.c src/linked_list.c
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Compile .c files into .o files
%.o: %.c include/book.h include/fileio.h include/menu.h include/linked_list.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
