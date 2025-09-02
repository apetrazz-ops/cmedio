CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2 -g -Iinclude

SRC = $(wildcard src/*.c src/lib/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))

all: build/app/demo

build/app/demo: $(OBJ)
	mkdir -p build/app
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
