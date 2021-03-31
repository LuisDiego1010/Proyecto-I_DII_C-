cmake_minimum_required(VERSION 3.17)
project(Proyecto_I_DII_C_)

set(CMAKE_CXX_STANDARD 14)

include_directories(Client)

add_executable(Client
        Client/Server_Socket.cpp
        Client/Server_Socket.h "Client/Main Client.cpp")
add_executable(Server
        Server/Client_Socket.cpp
        Server/Client_Socket.h
        "Server/Main Server.cpp")