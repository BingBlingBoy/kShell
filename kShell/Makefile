CC=gcc
CFLAGS = -I.
DEPS = main.h

all: main.o
	$(CC) -o kshell -Wall -Wextra -pedantic main.c file_loc.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf kshell main.o
