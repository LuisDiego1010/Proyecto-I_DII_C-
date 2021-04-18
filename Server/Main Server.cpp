//
// Created by 2001i on 30/3/2021.
//



#include <zmqpp/socket.hpp>
#include <zmqpp/context.hpp>
#include <zmqpp/message.hpp>
#include "Parser.h"

using namespace zmqpp;


void test();

/**
 * \brief Main of the server recieve from a Reply socket, do thing that are in the string and reply a json whit the actual state.
 *
 * @return
 */
int main(){
    cout<<"init"<<endl;
    test();
    cout<<"test runned"<<endl;
    const endpoint_t endpoint ="tcp://*:4040";
//    // initialize the 0MQ context
//    zmqpp::context context;
//
//    // generate a reply socket
//    zmqpp::socket_type type = zmqpp::socket_type::reply;
//    socket Socket= socket (context, type);
//
//    // bind to the socket
//    Socket.bind(endpoint);
//
//    std::string msg="b";
//    std::cout<<msg;
//    bool a=true;
//    while(a){
//        std::string Request;
//        Socket.receive(Request);
//        std::cout<<"hello";
//        std::cout<<Request<<"hello";
////        call to things
//
//        message_t reply;
////        reply.copy(msg.data());
//        Socket.send(R"({"text":"hola","logger":"error"})");
//
//        if (msg.empty()) {
//            return 0;
//
//        }
//        a= false;
//    }

}
void test(){
    auto * parser= new Parser;
    string a=R"({"type":"assign","logger":"error","left":"hello im̀ left", "rigth":"hello im̀ right"})";
    parser->Extract_instruction(a);
}