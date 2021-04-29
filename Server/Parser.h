//
// Created by isaac on 9/4/21.
//

#ifndef PROYECTO_I_DII_C__PARSER_H
#define PROYECTO_I_DII_C__PARSER_H


#include "Llist.h"
#include "LNode.h"
#include "MemoryController.h"
#include <nlohmann/json.hpp>


/**
 * @class class that determines what to do with the instruction received by the socket.
 * See class and Extract Instruction.
 */

class Parser {
private:

public:
    Parser();

    static string logg;
    static string out;

    static Parser *get_Parser();

    static Parser *self;
    MemoryController *Controller;

    /**
     * \brief Function that order a MemoryController to define a new variable
     * @param id
     * @param type
     */
    LNode *Define(const string&, const string&);

    /**
     * \brief function to assign a value to a variable by it tag
     * @param tag
     * @param value
     */
    void Assign(const string&, string);

    /**
     * \brief get the LNode of a objet property or a variable
     * @return
     */
    LNode * Aux_Assign(const string&);

    /**
     * \brief Recursive function that determine what to do with the instruction.
     * @param instruction
     */
    void Extract_instruction(const string &instruction);

    /**
     * Auxiliary function to be called by another fucntions to do arithmetic
     * @param instruction
     */
    string Instruction_Aux(string instruction);
    /**
     *Generate  the Json from the memory view, logger and the out
     */
    string Generate_Json();
    /**
     * Get the las nexted scope.
     */
    static Scope * GetLastScope();
};


#endif //PROYECTO_I_DII_C__PARSER_H
