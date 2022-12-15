# === MAKEFILE FOR EMULATOR ===

# Output 1 : Builds project into a static library (For Linux) found in lib directory
# Output 2 : Builds testBed.c into a binary found in the build folder


# === COMPILATION OPTIONS ===

CC=gcc
# CFLAGS= -Wall -Werror -g -fsanitize=address,leak,undefined # USE THESE FLAGS WHEN COMPILING TO CHECK FOR LEAKS ETC
CFLAGS= -fPIC # USE THESE FLAGS FOR COMPILING TO TEST


# === PATH AND OUTPUT OPTIONS ===

SRC_DIR=src
OBJ_DIR=obj
LIB_DIR=lib
TEST_DIR=../tests
INCLUDE_DIR=include
BUILD_DIR=build

EXEC_NAME=testBed
STATIC_LIB_NAME=libCpuEmulator

OUTPUT=$(BUILD_DIR)/$(EXEC_NAME)

# === SOURCE AND OBJECT PATTERNS ===

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# === BUILD RULES ===

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
	objdump -t $(LIB_DIR)/$(STATIC_LIB_NAME).a > $(LIB_DIR)/symbolTable.txt


clean:
	rm -r $(OBJ_DIR)/* $(BUILD_DIR)/* $(LIB_DIR)/*


# === OLD BUILD RULES (May need later) ===

# # Copy Library to test folder (Inefficient)
# copyStaticLibrary : 
# 	cp -f $(LIB_DIR)/$(STATIC_LIB_NAME).a $(TEST_DIR)/$(STATIC_LIB_NAME).a

# all : $(OUTPUT) $(LIB_DIR)/$(STATIC_LIB_NAME).a $(BUILD_DIR)/testLink

# $(OUTPUT) : emulatorRun.c $(OBJ_FILES)
# 	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) emulatorRun.c $(OBJ_FILES) -o $@