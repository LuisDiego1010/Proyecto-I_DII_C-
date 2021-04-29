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
#include "loggerS.h"


using namespace zmqpp;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace logging = boost::log;
namespace keywords = boost::log::keywords;
namespace src = boost::log::sources;

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT (loggerC, src::logger_mt);

void test();


void init_loggin() {
    logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");
    logging::add_file_log(
            keywords::auto_flush = true,
            keywords::file_name = "registerC!",
            keywords::format = "[%TimeStamp%]  [%Severity%] %Message% [%ThreadID%]"
    );
    logging::core::get()->set_filter(
            logging::trivial::severity >= logging::trivial::info);
}

/**
 * \brief Main of the server recieve from a Reply socket, do thing that are in the string and reply a json whit the actual state.
 *
 * @return
 */
int main(int argc, char *argv[]) {
    string endp="4040";
    if(argc>1){
        endp=argv[1];
        MemoryController::size=std::stoi(argv[2]);
    }else{
        MemoryController::size=10;
    }
    loggerC::get();
    cout << "init" << endl;
    test();
    cout << "test runned" << endl;
    const endpoint_t endpoint = "tcp://*:"+endp;
    // initialize the 0MQ context
    zmqpp::context context;

    // generate a reply socket
    zmqpp::socket_type type = zmqpp::socket_type::reply;
    zmqpp::socket Socket =  zmqpp::socket(context, type);

    // bind to the socket
    Socket.bind(endpoint);

    std::string msg = "b";
    std::cout << msg;
    Parser *parsing = new Parser();

    bool a = true;
    BOOST_LOG_TRIVIAL(info) << "Waiting for data";
    while (a) {

        std::string Request;
        Socket.receive(Request);
        std::cout << "recieved data";
        std::cout << Request << "=data";
//        call to things
        Parser::logg +=
                "started server at: [" + to_simple_string(boost::posix_time::second_clock::local_time()) + "]\n";
        BOOST_LOG_TRIVIAL(info) << "Send data";
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
    BOOST_LOG_TRIVIAL(info) << "The parser is extracting the instructions";
}