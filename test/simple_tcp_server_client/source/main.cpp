#include "tcp_server.h"

static void do_something(int connfd) {
    char rbuf[64] = {};
    ssize_t n = read(connfd, rbuf, sizeof(rbuf) - 1);

    if(n < 0){
        printf("read() error!\n");
        return;
    }
    printf("client says: %s\n", rbuf);

    char wbuf[] = "world";
    write(connfd, wbuf, strlen(wbuf));
}

int main(int argc, char *argv[]){
    //Initializations
    int fd = socket(AF_INET, SOCK_STREAM, 0;
    int val = 1;

    //set socket options
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

    //Address binding
    struct sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = ntohs(1234);
    addr.sin_addr.s_addr = ntohl(0);

    int rv = bind(fd, (const sockaddr *)&addr, sizeof(addr));
    if(rv) {
        printf("binding failed!\n");
    }

    //Allow socket to begin listening for connections
    rv = listen(fd, SOMAXCONN);
    if(rv) {
        printf("listen failed!\n");
    }

    //Accept connections
    while(1) {
        struct sockaddr_in client_addr = {};
        socklen_t addrlen = sizeof(client_addr);
        
        int connfd = accept(fd, (struct sockaddr *)&client_addr, &addrlen);
        if(connfd < 0) {
            printf("Error with accepting connection\n");
            continue;
        }

        do_something(connfd);
        close(connfd);
    }

    return 0;
}