CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c, build/%.o, $(SOURCES))

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

bin/program: $(OBJECTS)
	@mkdir -p bin
	$(CC) $(CFLAGS) $(OBJECTS) -o bin/program
