
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "network/networktypes.h"
#include "network/tcp.h"

//
// TCP Server functions
//
__inline struct sockaddr_in* alloc_sockaddr_in(const char* address, int port);

int tcp_accept(Socket* server, Socket** client){
	struct sockaddr_in* client_address = malloc(sizeof *client_address);
	socklen_t len = sizeof *client_address;
	
	int fd = accept(server->socket, (struct sockaddr*) client_address, &len);
	if(fd >= 0){
		*client = alloc_socket(fd, (struct sockaddr*) client_address);
	}else{
		free(client_address);
	}
	return fd;
}

Socket* tcp_bind(const char* address, int port) {
	struct sockaddr_in* addr;
	int fd;
	
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd < 0){
		return NULL;
	}
	addr = alloc_sockaddr_in(address, port);
	
	if(!bind(fd, (struct sockaddr*) addr, sizeof *addr)){
		free(addr);
		return NULL;
	}
	if(listen(fd,SOMAXCONN)){
		free(addr);
		return NULL;
	}
	
	return alloc_socket(fd, (struct sockaddr*) addr);
}

__inline struct sockaddr_in* alloc_sockaddr_in(const char* address, int port) {
	struct sockaddr_in* addr = malloc(sizeof *addr);
	addr->sin_family = AF_INET;
	addr->sin_port = htons(port);
	inet_aton(address, &addr->sin_addr);
	return addr;
}