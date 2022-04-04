#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <config.h>
#include <stdio.h>
#include <getopt.h>
#include <sys/types.h>

#include "system.h"



int main(void){

    struct sockaddr_in serv_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if( sockfd < 0 ) {
        printf("socket error\n");
        return 0;
    }
    printf("Opened fd %d\n", sockfd);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = 0;
     bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    socklen_t len = sizeof(serv_addr);
if (getsockname(sockfd, (struct sockaddr *)&serv_addr, &len) == -1) {
    perror("getsockname");
    return 0
    ;
}
    printf("port number %d\n", ntohs(serv_addr.sin_port));

    return 0;


}
