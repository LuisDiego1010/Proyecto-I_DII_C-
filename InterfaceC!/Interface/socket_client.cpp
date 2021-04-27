#include "socket_client.h"
#include "zmqpp/zmqpp.hpp"
#include <QJsonObject>
#include <QJsonDocument>

void Socket_Client::Init() {

    // bind to the socket

    socket->connect("tcp://127.0.0.1:4040");

}

QJsonDocument Socket_Client::Comunicatte(std::string msg) {
    QString Qjsonstring;
    QJsonDocument Json;
    std::string Request;
    socket->send(msg);
    std::cout<<"sended"<<std::endl;
    std::cout<<Request<<std::endl;
    socket->receive(Request);
    std::cout<<Request<<std::endl;
    Qjsonstring= QString::fromStdString(Request);
    std::cout<<"recieved";
    std::cout<<Request;
    Json=QJsonDocument::fromJson(Qjsonstring.toUtf8());
    return Json;
}

Socket_Client::Socket_Client() {
    this->Init();
}
