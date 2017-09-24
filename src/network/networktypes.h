#ifndef NETWORKTYPES_H
#define NETWORKTYPES_H

#include <stdlib.h>
#include <sys/socket.h>

typedef struct {
	int socket;
	struct sockaddr* address;
} Socket;

__inline Socket* alloc_socket(int fd, struct sockaddr* address) {
	Socket* sock = malloc(sizeof *sock);
	sock->socket = fd;
	sock->address = address;
	return sock;
}


#endif /* NETWORKTYPES_H */