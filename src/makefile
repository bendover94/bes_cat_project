CC=gcc
CFLAGS=-Wall -g

all: server client 

server: server.o socketlayer.o
	$(CC) $(CFLAGS) server.o socketlayer.o -o server

client: client.o socketlayer.o
	$(CC) $(CFLAGS) client.o socketlayer.o -o client

socketlayer.o: socketlayer.c socketprx.h
	$(CC) $(CFLAGS) -c socketlayer.c

server.o: server.c
	$(CC) $(CFLAGS) -c server.c

client.o: client.c
	$(CC) $(CFLAGS) -c client.c

clean:
	rm -rf *.o server client 
