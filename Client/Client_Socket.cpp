//
// Created by 2001i on 30/3/2021.
//

#include "Client_Socket.h"

#include <cstdio>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>
#include <netdb.h>

using namespace std;

Client_Socket::Client_Socket() {
    int port=4040, client_len;
    struct sockaddr_in server_dir;
    struct hostent *server;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 1){
        cout<<"error in first creation of client socket, please see the log";
//        logger call
    }
    // connect to the server
    server=gethostbyname("localhost");
    bzero((char*) &server_dir,sizeof (server_dir));
    server_dir.sin_family=AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_dir.sin_addr.s_addr, server->h_length );
    server_dir.sin_port=htons(port);
    if (connect(client_socket, (struct sockaddr*) &server_dir, sizeof(server_dir)) < 0){
        cout<<"error in the connection of the socket to the server, please see the log";
//        logger call

    }

}

void Client_Socket::send(string *msg) {
    int msg_len= msg->size();
//    call to logger
    msg_len=write(client_socket, msg, msg_len);
//    call to logger
    if (msg_len<0){
        cout<<"the server can not sent data to client in this moment, please see logger";
        //call to logger
    }
}

void Client_Socket::recieve() {
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

}

void Client_Socket::error(const char *msg) {

}
