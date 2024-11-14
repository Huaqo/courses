# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Target executable
TARGET = prog

# Object files
OBJS = stack.o prog.o

# Default rule to build the target executable
all: $(TARGET)

# Rule to build the target executable from object files
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile stack.c to object file
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

# Rule to compile prog.c to object file
prog.o: prog.c stack.h
	$(CC) $(CFLAGS) -c prog.c

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)