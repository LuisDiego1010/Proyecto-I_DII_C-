//
// Created by 2001i on 30/3/2021.
//


#include "Server_Socket.h"
#include <cstdio>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>

Server_Socket::Server_Socket() {

    int port=4040, client_len;
    struct sockaddr_in server_dir, client_dir;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 1){
        cout<<"error in first creation of server, please see the log";
//        logger call
    }
    // bindig the socket
    bzero((char*) &server_dir,sizeof (server_dir));
    server_dir.sin_family=AF_INET;
    server_dir.sin_port=htons(port);
    server_dir.sin_addr.s_addr=INADDR_ANY;
    if (bind(server_socket, (struct sockaddr*) &server_dir, sizeof(server_dir)) < 0){
        cout<<"error in the bindig of the socket and the port, please see the log";
//        logger call

    }

    //connecting to client
    listen(server_socket, 5);
    client_len= sizeof(client_dir);
    client_socket= accept(server_socket, (struct sockaddr*) &client_dir, reinterpret_cast<socklen_t *>(&client_len));
    if (client_socket<0){
        cout<<"conection to client failed, please see the log";
        //        logger call


    }
}

void Server_Socket::error(const char *msg) {
perror(msg);
//call logger
    return;
}

void Server_Socket::send(string* msg) {
    int msg_len= msg->size();
//    call to logger
    msg_len=write(client_socket, msg, msg_len);
//    call to logger
    if (msg_len<0){
        cout<<"the server can not sent data to client in this moment, please see logger";
        //call to logger
    }
}

void Server_Socket::recieve() {
    char buffer[256];
    int msg_len;
    bool a= true;
    while (a){
        bzero(buffer,256);
        msg_len=read(client_socket, buffer, 255);
        if(msg_len<0){
            cout<<"the message can not be readed, please see the log";
//            call to logger
        }
        msg_in=(string)buffer;
        if (msg_in=="server_quit.true"){
            a= false;
        }

    }
    msg_in="Server_quit.true";
}

