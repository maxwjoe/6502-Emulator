CC = gcc
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

SRC=../src
OBJ=../obj
INCLUDE=../include
BINDIR=../bin

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BIN=../bin/testRun

all:$(BIN)

$(BIN): testRun.o ../obj/CPU6502.o ../obj/Memory.o ../obj/Instructions.o ../obj/AddressModes.o ../obj/Operations.o
	$(CC) $(CFLAGS) testRun.o ../obj/CPU6502.o ../obj/Memory.o ../obj/Instructions.o ../obj/AddressModes.o ../obj/Operations.o -o $@


clean:
	rm -r $(BINDIR)/* $(OBJ)/*