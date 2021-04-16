#ifndef SOCKET_H
#define SOCKET_H
#include <zmqpp/zmqpp.hpp>
#include <QStringLiteral>

class Socket
{
public:
    static const zmqpp::endpoint_t endpoint;

       // initialize the 0MQ context
       zmqpp::context context;

       // generate a request socket
       zmqpp::socket_type type;

       zmqpp::socket socket;
    void Init();
};

#endif // SOCKET_H
