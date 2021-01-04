CC=gcc
CFLAGS=-Wall -g

all: mainapp 

mainapp: main.o common.o server.o client.o
	$(CC) $(CFLAGS) main.o common.o -o server.o client.o  

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

common.o: common.c
	$(CC) $(CFLAGS) -c common.c

server.o: server.c
	$(CC) $(CFLAGS) -c server.c

client.o: client.c
	$(CC) $(CFLAGS) -c client.c

clean:
	rm -rf *.o main
