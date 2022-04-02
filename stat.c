#include <linux/kernel.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>



asmlinkage long sys_pport(void){

    struct sockaddr_in serv_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if( sockfd < 0 ) {
        printk("socket error\n");
        return 0;
    }
    printk("Opened fd %d\n", sockfd);
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
    printk("port number %d\n", ntohs(serv_addr.sin_port));
    if (close (sockfd) < 0 ) {
    }

    return 0;


}
