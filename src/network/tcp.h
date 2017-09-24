#ifndef TCP_H
#define TCP_H

#include <sys/socket.h>

#include "network/networktypes.h"

//
// TCP Server functions
//

/** 
* tcp_bind will create and bind a socket to the given address and port.
* 
* @param address address to bind socket to
* @param port
*
* @retrun newly created Socket; 0, if connetion failed 
*/
Socket* tcp_bind(const char* address, int port);

/** 
* tcp_accept will accept sockets and create a new Socket struct.
* EAGAIN or EWOULDBLOCK
* 
* @param server socket to use to accept
* @param client output socket, allocation happens inside the function.
*
* @retrun the result of the accept function.
*/
int tcp_accept(Socket* server, Socket** client);

//
// TCP Client functions
//

/** 
* tcp_connect will connecto to the address given in the parameters.
* 
* @param host address to connect to
* @param port
*
* @retrun newly created Socket; 0, if connetion failed 
*/
Socket* tcp_connect(const char* host, int port);

/** 
* Write the buffer to the socket.
* 
* @param socket pointer to Socket struct created by tcp_connect.
* @param buffer data to send.
* @param size buffer size.
*
* @retrun number of bytes written.
*/
int tcp_write(Socket* socket, const char* buffer, int size);

/** 
* Read bytes from the socket.
* 
* @param socket pointer Socket struct created by tcp_connect
* @param buffer data received.
* @param size buffer size.
*
* @retrun number of bytes received
*/
int tcp_read(Socket* socket, char* buffer, int size);

//
// Socket functions
//

/** 
* Closes the socket and frees the memory for the structure.
* 
* @param socket pointer Socket struct created by tcp_connect
*
* @retrun 0, if succeeded; non-zero otherwise
*/
int tcp_close(Socket* socket);

/** 
* Sets the socket to be in non-blocking mode.
* 
* @param socket pointer to Socket.
* @param ms amount of time in milliseconds for the read to return.
*
* @retrun 0 if success, non-zero otherwise 
*/
int tcp_set_timeout(Socket* socket, int ms);


#endif /* TCP_H */
