//
// Created by 2001i on 30/3/2021.
//

#ifndef PROYECTO_I_DII_C_SOCKET_H
#define PROYECTO_I_DII_C_SOCKET_H


#include <string>
#include <cstdio>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>

#define PORT 8080

using namespace std;


//!
//! \brief Server class which connect to client. Only one for server ned to be created. Use port 4040 in local_host
//!
class Server_Socket {
    int server_socket, client_socket;
    string msg_in;
    Server_Socket();
    void send(string* msg);
    void recieve();
    void error(const char *msg);


};


#endif //PROYECTO_I_DII_C_SOCKET_H
