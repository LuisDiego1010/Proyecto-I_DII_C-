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

void Parser::Instruction_Aux(string instruction) {

}

void Parser::Define_assign(string id, string type, string value) {

}

void Parser::Assign(string id, string value) {

}

void Parser::Define(string id, string type) {

}
