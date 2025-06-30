#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>




int client(char *port_no, char *ip_addr){

char buffer[256];
int sock_fd, portno;
struct sockaddr_in serv_addr;
socklen_t clien_len;
struct hostent *server;
portno = atoi(port_no);
server = gethostbyname(ip_addr);


bzero((char *) &serv_addr, sizeof(serv_addr));


serv_addr.sin_family = AF_INET;

bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr , server->h_length);
serv_addr.sin_port = htons(portno);

sock_fd = socket(AF_INET, SOCK_STREAM, 0);

connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

while(1){

bzero(buffer, 255);

fgets(buffer, 255, stdin);


int wr = write(sock_fd, buffer, strlen(buffer));


printf("client: %s/n", buffer);

if(strncmp(buffer, "bye", 3) == 0){
break;
}

bzero(buffer, 255);



int re = read(sock_fd, buffer, 255);

printf("server: %s/n", buffer);


}
close(sock_fd);


return 0;
}
