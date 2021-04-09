//
// Created by 2001i on 30/3/2021.
//



#include <zmqpp/socket.hpp>
#include <zmqpp/context.hpp>
#include <zmqpp/message.hpp>

using namespace zmqpp;




/**
 * \brief Main of the server recieve from a Reply socket, do thing that are in the string and reply a json whit the actual state.
 *
 * @return
 */
int main(){
    const endpoint_t endpoint ="tcp://*:4040";
    // initialize the 0MQ context
    zmqpp::context context;

    // generate a reply socket
    zmqpp::socket_type type = zmqpp::socket_type::reply;
    socket Socket= socket (context, type);

    // bind to the socket
    Socket.bind(endpoint);

    std::string msg="b";
    std::cout<<msg;
    bool a=true;
    while(a){
        std::string Request;
        Socket.receive(Request);
        std::cout<<Request;
//        call to things

        message_t reply;
//        reply.copy(msg.data());
        Socket.send("server");

        if (msg.empty()) {
            return 0;

        }
        a= false;
    }

}
