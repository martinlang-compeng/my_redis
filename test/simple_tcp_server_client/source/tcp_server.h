#ifndef __TCP_SERVER_H__
#define __TCP_SERVER_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int tcp_server_init();

int tcp_server_bind();

int tcp_server_listen();

#endif //__TCP_SERVER_H__