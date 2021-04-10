//
// Created by isaac on 9/4/21.
//

#include "Parser.h"
Parser *Parser ::self;

Parser *Parser::get_Parser() {
    if (self== nullptr){
        self =new Parser;
    }
    return self;
}

void Parser::Extract_instruction(string instruction) {
    
}
