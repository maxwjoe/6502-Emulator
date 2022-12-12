
# === COMPILATION OPTIONS ===

CC=gcc
CFLAGS= -Wall -Werror -g -fsanitize=address,leak,undefined

# === PATH AND OUTPUT OPTIONS ===

SRC_DIR=src
OBJ_DIR=obj
LIB_DIR=lib
INCLUDE_DIR=include
BUILD_DIR=build

EXEC_NAME=testBed
STATIC_LIB_NAME=libCpuEmulator

OUTPUT=$(BUILD_DIR)/$(EXEC_NAME)


# === SOURCE, OBJECT AND LIBRARY FILES ===

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# === BUILD RULES ===

# all : $(OUTPUT) $(LIB_DIR)/$(STATIC_LIB_NAME).a $(BUILD_DIR)/testLink
all : $(LIB_DIR)/$(STATIC_LIB_NAME).a $(BUILD_DIR)/$(EXEC_NAME)

# Build Objects
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Build Static Library
$(LIB_DIR)/$(STATIC_LIB_NAME).a : $(OBJ_FILES)
	ar rcs $(LIB_DIR)/$(STATIC_LIB_NAME).a $(OBJ_FILES)

# Static Linkage to build testBed executable
$(BUILD_DIR)/$(EXEC_NAME) : testBed.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $^ -L. -l:$(LIB_DIR)/$(STATIC_LIB_NAME).a

clean:
	rm -r $(OBJ_DIR)/* $(BUILD_DIR)/* $(LIB_DIR)/*


# === OLD BUILD RULES (May need later) ===


# $(OUTPUT) : emulatorRun.c $(OBJ_FILES)
# 	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) emulatorRun.c $(OBJ_FILES) -o $@