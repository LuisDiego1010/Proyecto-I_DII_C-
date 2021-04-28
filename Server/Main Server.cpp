//
// Created by 2001i on 30/3/2021.
//



#include <zmqpp/socket.hpp>
#include <zmqpp/context.hpp>
#include <zmqpp/message.hpp>
#include "Llist.h"
#include "Parser.h"
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/core.hpp>
#include <boost/date_time.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/global_logger_storage.hpp>

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT (loggerC, src::logger_mt);

using namespace zmqpp;
void test();

/**
 * \brief Main of the server recieve from a Reply socket, do thing that are in the string and reply a json whit the actual state.
 *
 * @return
 */
int main() {
    cout << "init" << endl;
    test();
    cout << "test runned" << endl;
    const endpoint_t endpoint = "tcp://*:4040";
    // initialize the 0MQ context
    zmqpp::context context;

    // generate a reply socket
    zmqpp::socket_type type = zmqpp::socket_type::reply;
    socket Socket = socket(context, type);

    // bind to the socket
    Socket.bind(endpoint);

    std::string msg = "b";
    std::cout << msg;
    Parser *parsing = new Parser();

    bool a = true;
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Waiting for data\n";
    while (a) {
        std::string Request;
        Socket.receive(Request);
        std::cout << "recieved data";
        std::cout << Request << "=data";
//        call to things
        Parser::logg +=
                "started server at: [" + to_simple_string(boost::posix_time::second_clock::local_time()) + "]\n";
        message_t reply;
//        reply.copy(msg.data());
        parsing->Extract_instruction(Request);
        Request = parsing->Generate_Json();
        cout << Request;
        Socket.send(Request);

        if (msg.empty()) {
            return 0;

        }
        Parser::logg = "";
    }
}

void test() {
    auto *parser = new Parser();
    string a;
    string a2;
    string b;
    a = R"({"type":"assign","left":"int a","rigth":"15"})";
    a2 = R"({"type":"assign","left":"a","rigth":"16"})";
    b = R"({"type":"assign","left":"int b","rigth":"10"})";
    parser->Extract_instruction(a);
    cout << parser->Generate_Json();
    parser->Extract_instruction(b);
    cout << parser->Generate_Json();
    parser->Extract_instruction(a2);
    cout << parser->Generate_Json();
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] The parser is extracting the instructions\n";
}