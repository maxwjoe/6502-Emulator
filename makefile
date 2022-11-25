CC = gcc
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

SRC=src
OBJ=obj
INCLUDE=include
BINDIR=bin

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BIN=bin/main

all:$(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	rm -r $(BINDIR)/* $(OBJ)/*