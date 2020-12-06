CC=gcc
CFLAGS=-Wall -g

all: mainapp 

mainapp: main.o common.o
	$(CC) $(CFLAGS) main.o common.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

common.o: common.c
	$(CC) $(CFLAGS) -c common.c

clean:
	rm -rf *.o main
