#include <sys/types.h>
#include <sys/socket.h>


#define PORTNUMBER

int main(int argc, char ** argv)
{
	"Systax for binding socket"
	"int bind (int s, const struct sockaddr name, int namelen);

	struct sockaddr_in server; 

	memset(&server, 0, sizeof(server));

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htnol(INADDR_ANY); 
	server.sin_port = htons (PORTNUMBER)
	



}
