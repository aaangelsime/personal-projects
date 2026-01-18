CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic

TARGET = myprogram
SRC = main.c

.PHONY: all makerun clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

makerun: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
