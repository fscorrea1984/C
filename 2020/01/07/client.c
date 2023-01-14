#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

    /*printf("\x1B[2J");
    printf("\x7");*/
    
    if (argc != 2) {
        fprintf(stderr, "usage: client hostname");
        exit(1);
    }
    
    int create_socket, on = 1;
    char buffer[2056];
    struct sockaddr_in address;
    struct hostent *he;
    //struct in_addr **addr_list;
    
    if((create_socket=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) > 0)
        printf("The socket was created\n");
    else { 
        printf("The socket was not created: %d\n", create_socket);
        abort();
    }
    
    setsockopt(create_socket, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(int));
    
    if((he = gethostbyname(argv[1])) == NULL) {
        herror("gethostbyname");
        return 1;
    }
    
    //addr_list = (struct in_addr **) he->h_addr_list;
    
    //char ip[100];
    //strcpy(ip, (const char *) inet_ntoa(*addr_list[0]));
    //puts(ip);
    //exit(1);
    bcopy(he->h_addr, &address.sin_addr, he->h_length);
    //address.sin_addr.s_addr = inet_addr("172.217.30.100");
    //address.sin_addr.s_addr = *(long *)(he->h_addr_list[0]);
    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    //inet_pton(AF_INET,argv[1],&address.sin_addr);
    
    //if(connect(create_socket, (struct sockaddr *) &address.sin_addr, sizeof(address)) == 0) {
    if(connect(create_socket, (struct sockaddr *) &address.sin_addr, sizeof(struct sockaddr_in)) == 0) {
        puts("Connect error");
        return 1;
    }
    
    puts("Connected");

    /*printf("The connection was accepted with the server %s...\n", inet_ntoa(address.sin_addr));
    
    do {
        gets(buffer);
        send(cria_socket, buffer, buffsize, 0);
        recv(create_socket, buffer, buffsize, 0);
        printf("Message received: %s\n", buffer);
        if (strcmp(buffer, "/q");
            printf("Message to send: ");
    } while(strcmp(buffer, "/q");
    
    close(create_socket);*/
    
    //buffer = "GET HTTP/1.1\r\n Host: www.google.com\r\n Keep-alive\r\n Cache-Control: max-age=0\r\n Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,;q=0.8\r\n User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:66.0) Gecko/20100101 Firefox/66.0\r\n";
    
    strcpy(buffer, "GET /\r\n");
    
    //int ret = send(create_socket, buffer, buffsize, MSG_NOSIGNAL);
    int ret = send(create_socket, "GET /\r\n", strlen("GET /\r\n"), MSG_NOSIGNAL);
    //int ret = write(create_socket, "GET /\r\n", strlen("GET /\r\n"));
    
    if (ret < 0) {
        printf("ret = %d\n", ret);
        goto LAB;
    }   
    
    //if(send(create_socket, buffer, buffsize, MSG_NOSIGNAL) < 0) {
     if (0)
LAB:    puts("Send failed");
        return 1;
    //}

    //puts("Data send\n");
    
    //if(recv(create_socket, buffer,  buffsize, 0) < 0)
        //puts("Recv failed");
    
    //puts("Reply received\n");
    //puts(buffer);
    
    close(create_socket);
    
    return 0;

}
