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

/** 
* Closes the socket and frees the memory for the structure.
* 
* @param socket pointer Socket struct
*
* @retrun 0, if succeeded; non-zero otherwise
*/
__inline int socket_close(Socket* socket){
	int res = shutdown(socket->socket, SHUT_RD);
	free(socket->address);
	free(socket);
	return res;
}

/** 
* Sets the socket to be in non-blocking mode.
* 
* @param socket pointer to Socket.
* @param ms amount of time in milliseconds for the read to return.
*
* @retrun 0 if success, non-zero otherwise 
*/
__inline int socket_set_timeout(Socket* socket, int ms){
	struct timeval timeout;      
    timeout.tv_sec = 0;
    timeout.tv_usec = ms * 1000;

	return setsockopt socket->socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

}

#endif /* NETWORKTYPES_H */