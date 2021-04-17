//
// Created by isaac on 13/4/21.
//

#ifndef PROYECTO_I_DII_C__JSON_PARSER_H
#define PROYECTO_I_DII_C__JSON_PARSER_H
#include <QTextStream>
#include <cstring>
#include <zmq.h>


class Json_parser {
public:
   std::string qt_json(QString a);
};


#endif //PROYECTO_I_DII_C__JSON_PARSER_H
