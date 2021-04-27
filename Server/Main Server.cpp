//
// Created by 2001i on 30/3/2021.
//



#include <zmqpp/socket.hpp>
#include <zmqpp/context.hpp>
#include <zmqpp/message.hpp>
#include "Llist.h"
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
    // initialize the 0MQ context
    zmqpp::context context;

    // generate a reply socket
    zmqpp::socket_type type = zmqpp::socket_type::reply;
    socket Socket= socket (context, type);

    // bind to the socket
    Socket.bind(endpoint);

    std::string msg="b";
    std::cout<<msg;
    Parser * parsing=new Parser();

    bool a=true;
    BOOST_LOG_TRIVIAL(info) << "Waiting for data";
    while(a){
        std::string Request;
        Socket.receive(Request);
        std::cout<<"recieved data";
        std::cout<<Request<<"=data";
//        call to things
        BOOST_LOG_TRIVIAL(info) << "Send data";
        message_t reply;
//        reply.copy(msg.data());
        parsing->Extract_instruction(Request);
        Request= parsing->Generate_Json();
        cout<< Request;
        Socket.send(Request);

        if (msg.empty()) {
            return 0;

        }
    }
}
void test(){
    auto * parser= new Parser();
    string a;
    string b;
    a = R"({"type":"assign","left":"int a","rigth":"15"})";
    b = R"({"type":"assign","left":"int b","rigth":"10"})";
    parser->Extract_instruction(a);
    cout<< parser->Generate_Json();
    parser->Extract_instruction(b);
    cout<< parser->Generate_Json();
    BOOST_LOG_TRIVIAL(info) << "The parser is extracting the instructions";
}