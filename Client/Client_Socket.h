//
// Created by 2001i on 30/3/2021.
//

#ifndef PROYECTO_I_DII_C__CLIENT_SOCKET_H
#define PROYECTO_I_DII_C__CLIENT_SOCKET_H

#include <cstdio>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>

using namespace std;

class Client_Socket{
    string msg_in;
        int client_socket;
        Client_Socket();
    void send(string* msg);
    void recieve();
    void error(const char *msg);
};


#endif //PROYECTO_I_DII_C__CLIENT_SOCKET_H
