// source: Rheinwerk Computing: C von A bis Z
//http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/025_c_netzwerkprogrammierung_006.htm##mja8101c6e0e4cb2e6fd8312114dad30d7

#include "socketprx.h"
#include "misc.h"

void test_socketlayer();

/* Die Funktion gibt aufgetretene Fehler aus und
 *  * beendet die Anwendung. */
int create_socket( int af, int type, int protocol ) {
    socket_t sock;
    const int y = 1;
    /* Erzeuge das Socket. */
    sock = socket(af, type, protocol);
    if (sock < 0)
        error_exit("Fehler beim Anlegen eines Sockets");

    /* Mehr dazu siehe Anmerkung am Ende des Listings ... */
    setsockopt( sock, SOL_SOCKET,
            SO_REUSEADDR, &y, sizeof(int));
    return sock;
}


// creates binding to socket 
void bind_socket(socket_t *sock, unsigned long adress,
        unsigned short port) {
    struct sockaddr_in server;
    memset( &server, 0, sizeof (server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(adress);
    server.sin_port = htons(port);
    if (bind(*sock, (struct sockaddr*)&server,sizeof(server)) < 0)
        error_exit("Kann das Socket nicht \"binden\"");
}


// tell socket to accept connections from clients
void listen_socket( socket_t *sock ) {
    if(listen(*sock, 5) == -1 )
        error_exit("Fehler bei listen");
}

/* Bearbeite die Verbindungswünsche von Clients.
 *  * Der Aufruf von accept() blockiert so lange,
 *   * bis ein Client Verbindung aufnimmt. */

// 
void accept_socket( socket_t *socket, socket_t *new_socket ){
    struct sockaddr_in client;
    unsigned int len;

    len = sizeof(client);
    *new_socket=accept(*socket,(struct sockaddr *)&client, &len);
    if (*new_socket  == -1)
        error_exit("Fehler bei accept");
}

/* Baut die Verbindung zum Server auf. */
void connect_socket(socket_t *sock, char *serv_addr,
        unsigned short port) {
    struct sockaddr_in server;
    struct hostent *host_info;
    unsigned long addr;

    memset( &server, 0, sizeof (server));
    if ((addr = inet_addr( serv_addr )) != INADDR_NONE) {
        /* argv[1] ist eine numerische IP-Adresse */
        memcpy( (char *)&server.sin_addr, &addr, sizeof(addr));
    }
    else {
        /* Für den Fall der Fälle: Wandle den
         *         * Servernamen bspw. "localhost" in eine IP-Adresse um. */
        host_info = gethostbyname( serv_addr );
        if (NULL == host_info)
            error_exit("Unbekannter Server");
        memcpy( (char *)&server.sin_addr, host_info->h_addr,
                host_info->h_length);
    }
    server.sin_family = AF_INET;
    server.sin_port = htons( port );
    /* Baue die Verbindung zum Server auf. */
    if (connect(
                *sock, (struct sockaddr *)&server, sizeof( server)) < 0)
        error_exit( "Kann keine Verbindung zum Server herstellen");
}

/* Daten versenden via TCP */
void TCP_send( socket_t *sock, char *data, size_t size) {
    if(send( *sock, data, size, 0) == -1 )
        error_exit("Fehler bei send()");
}

/* Daten empfangen via TCP */
void TCP_recv( socket_t *sock, char *data, size_t size) {
    unsigned int len;
    len = recv (*sock, data, size, 0);
    if( len > 0 || len != -1 )
        data[len] = '\0';
    else
        error_exit("Fehler bei recv()");
}

/* Socket schließen */
void close_socket( socket_t *sock ){
    close(*sock);
}

/* Unter Linux/UNIX ist nichts zu tun ... */
void cleanup(void){
    printf("Aufraeumarbeiten erledigt ...\n");
    return;
}
