#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
 
int main(int argc, char * argv[])
{
    if ( argc <= 2 )
    {
        printf("Usage: %s ip_address port_number\n", basename(argv[0]));
        return 1;
    }
 
    const char * ip = argv[1];
    int port = atoi(argv[2]);
 
    int ret = 0;
    struct sockaddr_in address;
    bzero(&address,sizeof(address));
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
 
    int sockfd = socket(PF_INET, SOCK_STREAM, 0);
    assert (sockfd >= 0);
 
    if ( connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0 )
    {
        printf("connect failed\n");
    }
    else
    {
        const char *oob_data = "abcdef";
        const char *normal_data = "1234";
        send(sockfd, oob_data, strlen("abcdef"), MSG_OOB);
        sleep(1);
        send(sockfd, normal_data,strlen("1234"),0);
        send(sockfd, normal_data,strlen("1234"),0);
    }
 
    close(sockfd);
    return 0;
}