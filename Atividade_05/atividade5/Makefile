SRC_DIR := src
TEST_DIR := tests
BIN_DIR := bin
CHECK404_DIR := check404
CC := gcc

PROBLEM_SET := pokedex

CPPFLAGS := -Iinclude -MMD -MP
CFLAGS   := -Wall
DLL_FLAGS := -fPIC -shared
LDFLAGS  := -Llib
LDLIBS   := -lm

.PHONY: all clean install test_files

all: $(PROBLEM_SET)

./dll:
	@mkdir -p ./dll

install:
	@cd ./$(TEST_DIR)/$(CHECK404_DIR); $(MAKE) install 

test_files: all
	@$(CC) ./tests/test_fila.c ./dll/pokedex.so -Wl,-rpath=./dll/ -o ./tests/test_fila.out
	@$(CC) ./tests/test_pokemon.c ./dll/pokedex.so -Wl,-rpath=./dll/ -o ./tests/test_pokemon.out
	@$(CC) ./tests/test_remove.c ./dll/pokedex.so -Wl,-rpath=./dll/ -o ./tests/test_remove.out
	@$(CC) ./tests/test_pokedex.c ./dll/pokedex.so -Wl,-rpath=./dll/ -o ./tests/test_pokedex.out

test: test_files
	python ./$(TEST_DIR)/$(CHECK404_DIR)/check404.py
	@$(MAKE) -s clean

$(PROBLEM_SET): $(BIN_DIR) ./dll
	@$(CC) $(SRC_DIR)/$(@).c $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(BIN_DIR)/$@.out
	@$(CC) $(SRC_DIR)/$(@).c $(CFLAGS) $(DLL_FLAGS) $(LDFLAGS) $(LDLIBS) -o ./dll/$@.so

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

run: $(filter-out run, $(MAKECMDGOALS))
	@for i in $^; do ./$(BIN_DIR)/$$i.out; done
	@$(MAKE) -s clean

clean:
	@$(RM) -rf $(BIN_DIR)
	@$(RM) ./tests/*.out
	@$(RM) -rf ./dll
