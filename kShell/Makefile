CC=gcc
CFLAGS = -I
DEPS = main.h

all: main.o
	$(CC) -o shell -Wall -Wextra -pedantic main.c 

# %.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf shell main.o
