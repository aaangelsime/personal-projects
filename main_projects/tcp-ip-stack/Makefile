# C compiler
CC = gcc

# C compiler flags
# -c     compile only (no linking)
# -g     debugging symbols
# -Wall  enable common warnings
# -std=c11 use C11 standard
CFLAGS = -c -g -Wall -std=c11

# Output binary
PROGRAM = main.out

# Source files
CFILES = main.c ethernet.c tap.c

# Object files (derived automatically)
OBJ = $(CFILES:.c=.o)

# Default target
all: $(PROGRAM)

# Link object files into final binary
$(PROGRAM): $(OBJ)
	$(CC) -o $@ $(OBJ)

# Compile each .c into .o
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Run program
run: $(PROGRAM)
	./$(PROGRAM)

# Clean build artifacts
clean:
	rm -f $(PROGRAM) $(OBJ)
