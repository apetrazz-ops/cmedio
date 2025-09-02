CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2 -g -Iinclude

SRC_LIB = $(wildcard src/lib/*.c)
OBJ_LIB = $(patsubst src/lib/%.c, build/lib/%.o, $(SRC_LIB))

# Programma principale
APP_SRC = src/main.c
APP_OBJ = build/main.o

TEST_SRC = $(wildcard tests/*.c)
TEST_OBJ = $(patsubst tests/%.c, build/tests/%.o, $(TEST_SRC))

all: build/app/demo

build/app/demo: $(APP_OBJ) $(OBJ_LIB)
	mkdir -p build/app
	$(CC) $(CFLAGS) -o $@ $^

build/main.o: src/main.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

build/lib/%.o: src/lib/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

build/tests/tests: $(OBJ_LIB) $(TEST_OBJ)
	mkdir -p build/tests
	$(CC) $(CFLAGS) -o $@ $^

build/tests/%.o: tests/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

test: build/tests/tests
	./build/tests/tests

clean:
	rm -rf build
