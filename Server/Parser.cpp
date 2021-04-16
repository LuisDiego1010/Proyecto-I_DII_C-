//
// Created by isaac on 9/4/21.
//

#include "Parser.h"
#include "iostream"

using namespace std;

Parser *Parser ::self;

Parser *Parser::get_Parser() {
    if (self== nullptr){
        self =new Parser;
    }
    return self;
}

void Parser::Extract_instruction(string instruction) {
    size_t equal=instruction.find('=');
    if (equal!=string::npos){
        string left=instruction.substr(0,equal);
        string right=instruction.substr(equal,instruction.length()-equal);
        cout<<left<<" left side"<<endl;
        cout<<right<<" right side"<<endl;
    }
}

void Parser::Instruction_Aux(string instruction) {

}

void Parser::Define_assign(string id, string type, string value) {

}

void Parser::Assign(string id, string value) {

}

void Parser::Define(string id, string type) {

}
