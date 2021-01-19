#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

void sig_handler(int signo)
{
//   if (signo == SIGINT)
    printf("received sig:%d \n",signo);
    // exit(1);
}

int main()
{
    int epfd, nfds;
    struct epoll_event event, events[5];
    char buf[256];

    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");
    if (signal(SIGTSTP, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");
    if (signal(SIGURG, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");

    epfd = epoll_create(1);
    event.data.fd = STDIN_FILENO;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &event);
    while (1) {
        nfds = epoll_wait(epfd, events, 5, -1);
        printf("nfds: %d, errno: %d, %s\n",nfds,errno,strerror(errno));
        int i;
        for (i = 0; i < nfds; ++i) {
            if (events[i].data.fd == STDIN_FILENO) {

                printf("hello world\n");
            }
        }
    }
}