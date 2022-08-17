#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>

int socket_connect(char *host,in_port_t port) {

	struct hostent *hp;
	struct sockaddr_in addr;
	int en = 1, sock;

	if( (hp = gethostbyname(host)) == NULL ) {
		perror("gethostbyname");
		exit(1);
	}

	//bcopy(hp->h_addr_list[0], &addr.sin_addr, hp->h_length);
	memcpy(&addr.sin_addr, hp->h_addr_list[0], hp->h_length);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	sock = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
	setsockopt(sock,IPPROTO_TCP,TCP_NODELAY, (const char *) &en, sizeof(int));

	if (sock == -1) {
		perror("setsockopt");
		exit(1);
	}

	if(connect(sock,(struct sockaddr *) &addr, sizeof(struct sockaddr_in)) == -1) {
		perror("setsockopt");
		exit(1);
	}

	return sock;
	
}

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {

	int fd;
	char buffer[BUFFER_SIZE];

	if (argc != 3) {
		fprintf(stderr,"Usage: %s hostname port\n",argv[0]);
		exit(1);
	}

	fd = socket_connect(argv[1],atoi(argv[2]));
	write(fd,"GET /\r\n",strlen("GET /\r\n"));
	//bzero(buffer,BUFFER_SIZE);
	memset(buffer,0,BUFFER_SIZE);

	while(read(fd,buffer,BUFFER_SIZE-1) != 0) {
		fprintf(stderr,"%s",buffer);
		//bzero(buffer,BUFFER_SIZE);
		memset(buffer,0,BUFFER_SIZE);
	}

	shutdown(fd,SHUT_RDWR);

	close(fd);

	return 0;

}
