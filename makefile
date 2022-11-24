CC = gcc
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

cpu : main.o CPU6502.o
	$(CC) $(CFLAGS) -o cpu main.o CPU6502.o

main.o : main.c CPU6502.h
	$(CC) $(CFLAGS) -c main.c CPU6502.h

CPU6502.o : CPU6502.c CPU6502.h
	$(CC) $(CFLAGS) -c CPU6502.c CPU6502.h

clean:
	rm -f *.o