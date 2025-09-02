CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2 -g -Iinclude
BUILD = build

LIB_SRC := $(wildcard src/lib/*.c)
LIB_OBJ := $(patsubst src/lib/%.c,$(BUILD)/lib/%.o,$(LIB_SRC))

APP_SRC := src/app/main.c
APP_OBJ := $(BUILD)/app/main.o
APP_BIN := $(BUILD)/app/app

TEST_SRC := tests/test_runner.c
TEST_OBJ := $(BUILD)/tests/test_runner.o
TEST_BIN := $(BUILD)/tests/tests

.PHONY: all clean test dirs

all: dirs $(APP_BIN)

dirs:
	mkdir -p $(BUILD)/lib $(BUILD)/app $(BUILD)/tests

$(BUILD)/lib/%.o: src/lib/%.c include/%.h | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/app/%.o: src/app/%.c | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(APP_BIN): $(LIB_OBJ) $(APP_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# ----- TEST -----
$(BUILD)/tests/test_runner.o: tests/test_runner.c | dirs
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BIN): $(LIB_OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -rf $(BUILD) compile_commands.json
