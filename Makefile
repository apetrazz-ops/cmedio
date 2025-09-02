CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2 -g -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))

all: build/app/demo

build/app/demo: $(OBJ)
	mkdir -p build/app
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build


test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -rf $(BUILD) compile_commands.json
