CC=gcc
CFLAGS=-Wall -g

all: server client 

server: server.o socketlayer.o 
	$(CC) $(CFLAGS) server.o socketlayer.o -o server

client: client.o socketlayer.o 
	$(CC) $(CFLAGS) client.o socketlayer.o -o client

socketlayer.o: socketlayer.c socketprx.h
	$(CC) $(CFLAGS) -c socketlayer.c

server.o: server.c misc.h file_io.c
	$(CC) $(CFLAGS) -c server.c

client.o: client.c file_io.h misc.h
	$(CC) $(CFLAGS) -c client.c

misc.o: misc.c misc.h
	$(CC) $(CFLAGS) -c misc.c

file_io.o: file_io.c file_io.h misc.h
	$(CC) $(CFLAGS) -c file_io.c

clean:
	rm -rf *.o server client 
