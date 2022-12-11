
# === COMPILATION OPTIONS ===

CC=gcc
CFLAGS= -Wall -Werror -g -fsanitize=address,leak,undefined

# === PATH AND OUTPUT OPTIONS ===

SRC_DIR=src
OBJ_DIR=obj
LIB_DIR=lib
INCLUDE_DIR=include
BUILD_DIR=build

EXEC_NAME=emulatorRun
OUTPUT=$(BUILD_DIR)/$(EXEC_NAME)


# === SOURCE, OBJECT AND LIBRARY FILES ===

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# === BUILD RULES ===

all : $(OUTPUT)

$(OUTPUT) : emulatorRun.c $(OBJ_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) emulatorRun.c $(OBJ_FILES) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -r $(OBJ_DIR)/* $(BUILD_DIR)/*
