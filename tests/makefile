# === COMPILATION OPTIONS ===

CXX=g++
CXXFLAGS=

# === PATHS ===


EAGLE_INCLUDE_DIR=Eagle/include
EAGLE_LIB_DIR=Eagle/lib

EMULATOR_INCLUDE_DIR=../emulator/include
EMULATOR_LIB_DIR=../emulator/lib

OBJ_DIR=obj
BIN_DIR=bin

# === FILES ===

TEST_EXEC_NAME=testBed
EAGLE_LIB_NAME=libEagle
EMULATOR_LIB_NAME=libCpuEmulator

# TEST_SRC_FILES = $(wildcard unitTests/*.cpp)
# TEST_OBJ_FILES = $(patsubst unitTests/%.cpp, unitTests/%.o, $(TEST_SRC_FILES))

# === RULES ===

all : $(BIN_DIR)/$(TEST_EXEC_NAME)



# Compile Testbed and Link against Static Libraries
$(BIN_DIR)/$(TEST_EXEC_NAME) : testBed.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -I$(EMULATOR_INCLUDE_DIR) -I$(EAGLE_INCLUDE_DIR) -o $@ $^ -L. -l:$(EMULATOR_LIB_DIR)/$(EMULATOR_LIB_NAME).a -l:$(EAGLE_LIB_DIR)/$(EAGLE_LIB_NAME).a


clean :
	rm -r $(BIN_DIR)/*