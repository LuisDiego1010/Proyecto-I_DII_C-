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
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/global_logger_storage.hpp>

using namespace zmqpp;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace logging = boost::log;
namespace keywords = boost::log::keywords;
namespace src=boost::log::sources;

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT (loggerC,src::logger_mt);

void test();


void init_loggin(){
    logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");
    logging::add_file_log(
            keywords::file_name="registerC!",
            keywords::format = "[%TimeStamp%]  [%Severity%] %Message% [%ThreadID%]"
            );
    logging::core::get()->set_filter(
    logging::trivial::severity >= logging::trivial::info);
    logging::add_common_attributes();
}

/**
 * \brief Main of the server recieve from a Reply socket, do thing that are in the string and reply a json whit the actual state.
 *
 * @return
 */
int main(){
    loggerC::get();
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
//    BOOST_LOG_TRIVIAL(info) << "Waiting for data";
//    while(a){
//        std::string Request;
//        Socket.receive(Request);
//        std::cout<<"hello";
//        std::cout<<Request<<"hello";
////        call to things
//        BOOST_LOG_TRIVIAL(info) << "Send data";
//        message_t reply;
////        reply.copy(msg.data());
//        Socket.send(R"({"memory":"hola","logger":"error", "out":"bye"})");
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
    BOOST_LOG_TRIVIAL(info) << "The parser is extracting the instructions";
}