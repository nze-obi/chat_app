#include <stdio.h>
#include "main.h"


int main(){
//char port_no[4];
char buffer;


printf("Press 1 for 'server': press 2 for 'client'\n");
buffer = getchar();


if(buffer=='2'){

char server_ip[16];
char port_no[4];


printf("enter server ip address\n");
fgets(server_ip, 15, stdin);

printf("enter port number/n");
fgets(port_no, 4, stdin);

printf("starting client/n"); 
client(port_no, server_ip);
}
else if(buffer=='1'){
char port_no[4];

printf("enter port number/n");
fgets(port_no, 4, stdin);
printf("starting server/n");
server(port_no);
}

return 0;
}
