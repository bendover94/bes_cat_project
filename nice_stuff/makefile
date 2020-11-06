CC=gcc
CFLAGS=-g

COMMOM_OBJECTS = common

all: $(COMMOM_OBJECTS) main something

common.0: commen.h common.c
	$(CC) $(CFLAGS) -c common.c


main: main.c
	$(CC) $(CFLAGS) main main.c $(COMMOM_OBJECTS)

something: something


clean:
	rm -rf *.o

