//
// Created by 2001i on 30/3/2021.
//

#include <zmqpp/zmqpp.hpp>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

using namespace zmqpp;
using namespace std;
void comunicate(string* msg, socket* Socket);
/**
 * \brief
 * Main, work with the socket reply and show the answer in the GUI
 * @return
 */
int main(){
//    Client
    const endpoint_t endpoint = "tcp://localhost:4040";

    // initialize the 0MQ context
    zmqpp::context context;

    // generate a request socket
    zmqpp::socket_type type = zmqpp::socket_type::request;
    socket Socket= socket (context, type);

    // bind to the socket
    Socket.connect("tcp://127.0.0.1:4040");


    string msg= "afff";
    cout<<"mm";
    comunicate(&msg,&Socket);

}

/**
 * \brief Send the line and receive json with the new state of the server
 * remember to free the return address after transform to json
 * @param msg the line to do
 * @param Socket Socket to sent
 * @return ptr to a address memory that storage the json as string, nedd to cast to message*
 */
void comunicate(string* msg, socket* Socket) {
    std::string Request;
    Socket->send(*msg);
    cout<<"yes1";
    cout<<Request;
    Socket->receive(Request);

    cout<<"yes2";
    cout<<Request;
    if (msg->empty()) {
        return ;

    }
    return ;
}



