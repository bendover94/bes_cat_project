// source: Rheinwerk Computing: C von A bis Z
//http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/025_c_netzwerkprogrammierung_006.htm##mja8101c6e0e4cb2e6fd8312114dad30d7

#ifndef SOCKETPRX_H_
#define SOCKETPRX_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "misc.h"

/* ein eigener primitver Datentyp für den Socket-Deskriptor */
#define socket_t int
/* Funktionsprototypen */
int create_socket( int af, int type, int protocol );
void bind_socket(socket_t
          *sock, unsigned long adress, unsigned short port);
void listen_socket( socket_t *sock );
void accept_socket( socket_t *new_socket, socket_t *socket );
void connect_socket(socket_t *sock, char *serv_addr,
         unsigned short port);
void TCP_send( socket_t *sock, char *data, size_t size);
void TCP_recv( socket_t *sock, char *data, size_t size);
void close_socket( socket_t *sock );
void cleanup(void);

#endif
