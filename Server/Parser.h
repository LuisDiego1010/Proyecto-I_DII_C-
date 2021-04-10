//
// Created by isaac on 9/4/21.
//

#ifndef PROYECTO_I_DII_C__PARSER_H
#define PROYECTO_I_DII_C__PARSER_H


#include "Llist.h"
#include "MemoryController.h"

class Parser {
private:

public:
    static Parser* get_Parser();
    static Parser* self;
    MemoryController* Controller= new MemoryController;

    void Extract_instruction(string instruction);

};


#endif //PROYECTO_I_DII_C__PARSER_H
