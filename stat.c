//#include<linux/kernel.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
// #include <errno.h>
//#include<stdio.h>


int main(void){

    struct sockaddr_in serv_addr;
    // if( argc < 2 )
    //     return 0;
    // int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if( sockfd < 0 ) {
        printf("socket error\n");
        return 0;
    }
    printf("Opened fd %d\n", sockfd);

     // bzero((char *) &serv_addr, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = 0;
     bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
     //if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {

        // if( errno == EADDRINUSE )
        // {
        //     printf("the port is not available. already to other process\n");
        // } else {
        //     printf("could not bind to process (%d) %s\n", errno, strerror(errno));
        // }
    //}

    socklen_t len = sizeof(serv_addr);
if (getsockname(sockfd, (struct sockaddr *)&serv_addr, &len) == -1) {
    perror("getsockname");
    return 0
    ;
}
    printf("port number %d\n", ntohs(serv_addr.sin_port));
    if (close (sockfd) < 0 ) {
        // printf("did not close fd: %s\n", strerror(errno));
        // return 0;
    }

    return 0;


}
