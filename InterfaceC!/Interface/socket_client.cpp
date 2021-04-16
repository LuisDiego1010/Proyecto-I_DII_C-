#include "socket_client.h"
#include "zmqpp/zmqpp.hpp"

void Socket::Init() {

    // generate a request socket
    type = zmqpp::socket_type::request;
    socket= zmqpp::socket (context, type);

}
