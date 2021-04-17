#ifndef SOCKET_H
#define SOCKET_H
#include <zmqpp/zmqpp.hpp>
#include <QStringLiteral>
#include <QJsonObject>
#include <QJsonDocument>


class Socket_Client
{
public:
    Socket_Client();
    zmqpp::context context;
    // generate a request socket
    zmqpp::socket_type type = zmqpp::socket_type::request;
    zmqpp::socket * socket= new zmqpp:: socket(context, type);

    void Init();
    QJsonDocument Comunicatte(std::string );
};

#endif // SOCKET_H
