#include <unistd.h>
#include <stdio.h>
#include <sys/epoll.h>

int main()
{
    int epfd, nfds;
    struct epoll_event event, events[5];
    char buf[256];
    epfd = epoll_create(1);
    event.data.fd = STDIN_FILENO;
// 实验1 当用户输入一组字符，这组字符被送入缓冲区，因为缓冲区由空变成不空，所以ET返回读就绪，输出”hello world”。
// 之后再次执行epoll_wait，但ET模式下只会通知应用进程一次，故导致epoll_wait阻塞。
// 如果用户再次输入一组字符，导致缓冲区内容增多，ET会再返回就绪，应用进程再次输出”hello world”。
// 如果将上面的代码中的event.events = EPOLLIN | EPOLLET;改成event.events = EPOLLIN;，即使用LT模式，则运行程序后，会一直输出hello world。
    // event.events = EPOLLIN | EPOLLET;
    event.events = EPOLLIN ;
    epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &event);
    while (1) {
        nfds = epoll_wait(epfd, events, 5, -1);
        int i;
        for (i = 0; i < nfds; ++i) {
            if (events[i].data.fd == STDIN_FILENO) {
// 实验2中使用的是LT模式，则每次epoll_wait返回时我们都将缓冲区的数据读完，下次再调用epoll_wait时就会阻塞，直到下次再输入字符。
// 如果将上面的程序改为每次只读一个字符，那么每次输入多少个字符，则会在屏幕中输出多少个“hello world”。有意思吧。
                // read(STDIN_FILENO, buf, sizeof(buf));

//实验3使用ET模式，但是每次读就绪后都主动对描述符进行EPOLL_CTL_MOD 修改EPOLLIN事件，由上面的描述我们可以知道，会再次触发读就绪，
//这样就导致程序出现死循环，不断地在屏幕中输出”hello world”。但是，如果我们将EPOLL_CTL_MOD 改为EPOLL_CTL_ADD，则程序的运行将不会出现死循环的情况。
                event.data.fd = STDIN_FILENO;
                event.events = EPOLLIN | EPOLLET;
                epoll_ctl(epfd, EPOLL_CTL_MOD, STDIN_FILENO, &event);

                printf("hello world\n");
            }
        }
    }
}