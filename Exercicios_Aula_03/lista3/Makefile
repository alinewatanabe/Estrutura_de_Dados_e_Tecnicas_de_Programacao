SRC_DIR := src
TEST_DIR := tests
BIN_DIR := bin
CHECK404_DIR := check404
CC := gcc

PROBLEM_SET := calculadora

CPPFLAGS := -Iinclude -MMD -MP
CFLAGS   := -Wall
DLL_FLAGS := -fPIC -shared
LDFLAGS  := -Llib
LDLIBS   := -lm

.PHONY: all clean install

all: $(PROBLEM_SET)

lib: ./dll
	-$(CC) $(SRC_DIR)/calculadora.c $(CFLAGS) $(DLL_FLAGS) $(LDFLAGS) $(LDLIBS) -o ./dll/calculadora.so

./dll:
	mkdir -p ./dll

install:
	@cd ./$(TEST_DIR)/$(CHECK404_DIR); $(MAKE) install 

test: lib all
	python3 ./$(TEST_DIR)/$(CHECK404_DIR)/check404.py
	@$(MAKE) -s clean

$(PROBLEM_SET): $(BIN_DIR) 
	-$(CC) $(SRC_DIR)/$(@).c $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(BIN_DIR)/$@.out

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

run: $(filter-out run, $(MAKECMDGOALS))
	@for i in $^; do ./$(BIN_DIR)/$$i.out; done
	@$(MAKE) -s clean

clean:
	@$(RM) -rf $(BIN_DIR)
	@$(RM) -rf ./dll
