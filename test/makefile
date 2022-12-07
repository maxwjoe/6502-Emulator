CC = gcc
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

SRC=../src
OBJ=../obj
INCLUDE=../include
BINDIR=../bin

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BIN=../bin/testLDA

all:$(BIN)

$(BIN): testLDA.o ../obj/CPU6502.o ../obj/Memory.o ../obj/Instructions.o
	$(CC) $(CFLAGS) testLDA.o ../obj/CPU6502.o ../obj/Memory.o ../obj/Instructions.o -o $@


clean:
	rm -r $(BINDIR)/* $(OBJ)/*