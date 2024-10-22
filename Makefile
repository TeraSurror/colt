# Define the compiler
CC = gcc

# Define compiler flags
CFLAGS = -Wall -Werror

# Use wildcard to find all .c files and create corresponding .o files
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Define the output executable name
OUT = colt

# Default target
all: $(OUT)

# Rule to link object files into the final executable
$(OUT): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Pattern rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the directory by removing object files and the executable
clean:
	rm -f $(OBJS) $(OUT)

.PHONY: all clean