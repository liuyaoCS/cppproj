#include <syslog.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <assert.h>
#include <errno.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <libgen.h>
 
#define MAX_EVENT_NUMBER 1024
static int pipefd[2];
static int connfd;
/*  
int setnonblocking( int fd )
{
    int old_option = fcntl( fd, F_GETFL );
    int new_option = old_option | O_NONBLOCK;
    fcntl( fd, F_SETFL, new_option );
    return old_option;
}
void addfd( int epollfd, int fd)
{
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl( epollfd, EPOLL_CTL_ADD, fd, &event );
    setnonblocking( fd );
}
void sig_handler( int sig )
{
    printf("收到信号 %d\n",sig);
    int save_errno = errno;
    int msg = sig;
    send(pipefd[1],(char *)&msg, 1, 0);
    errno = save_errno;
}
*/
#define BUF_SIZE 1024
void sig_urg( int sig )
{
    char buffe[BUF_SIZE];
    int save_errno = errno;
    memset(buffe, '\0',BUF_SIZE);
    int ret = recv( connfd, buffe, BUF_SIZE-1, MSG_OOB);
    printf("got %d bytes of oob data '%s'\n",ret, buffe);
    errno = save_errno;
}
 
void addsig( int sig ,void (*sig_handler)(int))
{
    struct sigaction sa;
    memset(&sa, '\0', sizeof( sa ));
    sa.sa_handler = sig_handler;
    sa.sa_flags = 0;
    sigemptyset( &sa.sa_mask ); //屏蔽所有信号
    assert( sigaction(sig, &sa, NULL) != -1 );
}
 
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
 
    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    assert (listenfd >= 0);
 
    ret = bind( listenfd, (struct sockaddr *)&address, sizeof(address) );
    if ( ret == -1 )
    {
        printf("errno id %s",strerror(errno));
        return 1;
    }
 
    ret = listen(listenfd, 5);
    assert( ret != -1);
 
    struct sockaddr_in client;
    socklen_t client_addrlenth = sizeof( client );
    connfd = accept( listenfd, (struct sockaddr *)&client, &client_addrlenth);
    if ( connfd < 0 )
    {
        printf("errno is: %d\n",errno);
    }
    else{
        //addsig(SIGURG, sig_urg);
         if ( signal(SIGURG, sig_urg)  < 0)
         {
            printf("注册失败,msg = %s\n",strerror(errno));
         }
        /* 使用SIGURG信号之前，我们必须设置socket的宿主进程或者进程组 */
        fcntl( connfd, F_SETOWN, getpid());
     
        char buffer[BUF_SIZE];
        
        while(1)
        {
            memset(buffer,'\0',BUF_SIZE);
            ret = recv( connfd, buffer, BUF_SIZE -1, 0);
            if ( ( ret <= 0 ) )
            {
                break;
            }
 
            printf("got %d bytes of normal data '%s'\n",ret, buffer);
        } 
            
        close(connfd);
    }
 
    close(listenfd);
    return 1;
}