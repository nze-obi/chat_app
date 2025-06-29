#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>





int server(char *port_no){


int sock_fd, newsock_fd, portno;
struct sockaddr_in serv_addr, clien_addr;
socklen_t clilen;

char buffer[255];

bzero((char *)&serv_addr, sizeof(serv_addr));
portno = atoi(port_no);


serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = INADDR_ANY;
serv_addr.sin_port = htons(portno);

sock_fd = socket(AF_INET, SOCK_STREAM, 0);


bind(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

listen(sock_fd, 5);

clilen = sizeof(clien_addr);

newsock_fd = accept(sock_fd, (struct sockaddr *) &clien_addr, &clilen);

while(1){

bzero(buffer, 255);


int re = read(newsock_fd, buffer, 255);

printf("client: %s/n", buffer);

bzero(buffer, 255);
fgets(buffer, 255, stdin);

int wr = write(newsock_fd, buffer, strlen(buffer));

printf("server: %s/n", buffer);

int i = strncmp("bye", buffer, 3);
if(i == 0){
break;
}



}
close(sock_fd);
close(newsock_fd);


return 0;
}
