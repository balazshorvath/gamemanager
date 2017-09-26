#ifndef NETWORKTYPES_H
#define NETWORKTYPES_H

#include <sys/socket.h>
#include "network/networktypes.h"

//
// Unix Domain Server functions
//

/** 
* unix_bind will create and bind a socket to the given path.
* uses unlink() to make sure the file is deleted after it's unused.
* 
* @param path path to the socket
*
* @retrun newly created Socket; 0, if connetion failed 
*/
Socket* unix_bind(const char* path);

/** 
* unix_accept will accept connections and create a new Socket struct.
* 
* @param server socket to use to accept
* @param client output socket, allocation happens inside the function.
*
* @retrun the result of the accept function.
*/
int unix_accept(Socket* server, Socket** client);

//
// Unix Domain Client functions
//

/** 
* unix_connect will connecto to the address given in the parameters.
* 
* @param host address to connect to
* @param port
*
* @retrun newly created Socket; 0, if connetion failed 
*/
Socket* unix_connect(const char* host);

/** 
* Write the buffer to the socket.
* 
* @param socket pointer to Socket struct created by unix_connect.
* @param buffer data to send.
* @param size buffer size.
*
* @retrun number of bytes written.
*/
int unix_write(Socket* socket, const char* buffer, int size);

/** 
* Read bytes from the socket.
* 
* @param socket pointer Socket struct created by unix_connect
* @param buffer data received.
* @param size buffer size.
*
* @retrun number of bytes received
*/
int unix_read(Socket* socket, char* buffer, int size);



#endif /* NETWORKTYPES_H */
