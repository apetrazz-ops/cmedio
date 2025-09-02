CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2 -g -Iinclude

SRC = $(wildcard src/*.c src/lib/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))

TEST_SRC = $(wildcard tests/*.c)
TEST_OBJ = $(patsubst tests/%.c, build/tests/%.o, $(TEST_SRC))

all: build/app/demo

build/app/demo: $(OBJ)
	mkdir -p build/app
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

build/tests/tests: $(OBJ) $(TEST_OBJ)
	mkdir -p build/tests
	$(CC) $(CFLAGS) -o $@ $^

build/tests/%.o: tests/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

test: build/tests/tests
	./build/tests/tests

clean:
	rm -rf build
