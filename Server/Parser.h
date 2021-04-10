//
// Created by isaac on 9/4/21.
//

#ifndef PROYECTO_I_DII_C__PARSER_H
#define PROYECTO_I_DII_C__PARSER_H


#include "Llist.h"
#include "MemoryController.h"
/**
 * @class class that determines what to do with the instruction received by the socket.
 * See class and Extract Instruction.
 */
class Parser {
private:

public:
    static Parser* get_Parser();
    static Parser* self;
    MemoryController* Controller= new MemoryController;
    /**
     * \brief Function that order a MemoryController to define a new variable
     * @param id
     * @param type
     */
    void Define(string id, string type);
    /**
     * \brief function to assign a value to a variable using it id
     * @param id
     * @param value
     */
    void Assign(string id , string value);
    /**
     * Auxiliary function, not expected to be called.
     * @param id
     * @param type
     * @param value
     */
    void Define_assign(string id, string type, string value);
    /**
     * \brief Recursive function that determine what to do with the instruction.
     * @param instruction
     */
    void Extract_instruction(string instruction);
    /**
     * Auxiliary function to be called by another fucntions
     * @param instruction
     */
    void Instruction_Aux(string instruction);

};


#endif //PROYECTO_I_DII_C__PARSER_H
