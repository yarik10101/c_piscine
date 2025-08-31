# Compiler
CC = gcc

# Compiler flags (warnings + debugging)
CFLAGS = -Wall -Wextra -Werror -g

# Executable name
TARGET = program

# Source files
SRCS = main.c ft.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation step
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
