cmake_minimum_required(VERSION 3.17)
project(Proyecto_I_DII_C_)

set(CMAKE_CXX_STANDARD 14)

include_directories(Client)

add_executable(Client
        Client/Client_Socket.cpp
        Client/Client_Socket.h
         "Client/Main Client.cpp")
add_executable(Server
        Server/Server_Socket.cpp
        Server/Server_Socket.h
        "Server/Main Server.cpp")