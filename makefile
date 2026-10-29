CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c, build/%.o, $(SOURCES))
TARGET = bin/program

all: $(TARGET)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	@mkdir -p bin
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -rf build bin

.PHONY: all clean
