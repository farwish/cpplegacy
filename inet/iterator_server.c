/**
 * 迭代服务器通常指单进程阻塞服务器。
 *
 * INADDR_ANY == 0.0.0.0 表示所有地址
 * 如果多个网卡，服务器可以在任一网络接口上接受请求，只区分端口号
 *
 * socket, bind, listen, accept
 *
 * PF_UNIX, PF_INET
 * "The protocol family generally is the same as the address family"
 * AF_UNIX, AF_INET
 *
 * @farwish
 */

#include <unistd.h>
// sprintf
#include <stdio.h>
// sockets
#include <sys/socket.h>
// memset
#include <string.h>
// time
#include <time.h>

int main(int argc, char *argv[])
{
    int sockfd, bind_ret, listen_ret, connfd;
    struct sockaddr address;
    time_t ticks;
    char buff[100];

    // `man 3 socket`
    // example use socket: man 3 getaddrinfo
    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
        sprintf("%s", "socket error\n"); return sockfd;
    }

    // 使用 address 之前初始化
    memset(&address, 0, sizeof(address));

    // bits/socket.h:148
    // sockaddr 结构

    // `man 3 bind`
    if ( (bind_ret = bind(sockfd, &address, sizeof(address))) < 0 ) {
        sprintf("%s", "bind error\n"); return bind_ret;
    }
    
    // `man listen`
    // maximum backlog: /proc/sys/net/core/somaxconn
    // set backlog: /proc/sys/net/ipv4/tcp_max_syn_backlog
    if ( (listen_ret = listen(sockfd, 10240)) < 0 ) {
        sprintf("%s", "listen error\n"); return listen_ret;
    }

    while (1) {
        if ( (connfd = accept(sockfd, (struct sockaddr *)NULL, NULL)) < 0 ) {
            sprintf("%s", "conn error\n"); return connfd;
        }

        ticks = time(NULL);

        snprintf(buff, sizeof(buff), "%.24s\n", ctime(&ticks));

        write(connfd, buff, strlen(buff));

        close(connfd);
    }
}
