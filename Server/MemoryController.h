//
// Created by isaac on 9/4/21.
//

#ifndef PROYECTO_I_DII_C__MEMORYCONTROLLER_H
#define PROYECTO_I_DII_C__MEMORYCONTROLLER_H

#include <cstdio>
#include "Llist.h"
#include "Scope.h"
#include "string.h"
#include <nlohmann/json.hpp>

using namespace std;

/**
 * @class Control the memory of the client, Use Linked list to storage metadata and ptr to the data.
 */
class MemoryController {
    static MemoryController *self;
    /**
     * Start of the memory block
     */
    void *ptr_start;
    /**
     * End of  the memory block
     */
    void *ptr_End;
    /**
     * ptr in the actual free to use scope
     */
    void *ptr_actual;
    /**
     * Scope to do a delete and delete all
     */
    Scope *Main_Scope;
    /**
     * Scope to work
     */
    Scope *Actual_Scope;
public:
    void *getPtrActual() const;
    static int size;


public:
    void *operator new(std::size_t);

    void operator delete(void *);

    MemoryController();

    /**
     * Create a new scope and replace the actual scope whit it
     */
    void new_scope();

    /**
     * Insert a new int in the actual scope
     */
    LNode *define_ints(const string &);

    /**
     * Insert a new char in the actual scope
     */
    LNode *define_chars(const string &);

    /**
     * Insert a new  Float in the actual scope
     */
    LNode *define_floats(string);

    /**
     * start to create a structure
     */
    LNode *define_structs(string);

    /**
     * Insert a new reference in the actual scope
     */
    LNode *define_references(string);

    /**
     * Insert a new long in the actual scope
     */
    LNode *define_longs(string);

    /**
     * Insert a double in the actual scope
     */
    LNode *define_doubles(string);

    void testing_scope();

    void increment_ptr(size_t);

    Scope *getMainScope() const;

    /**
     * \brief search for a Variable in the availables scopes
     * @param tag
     * @return the LNode that containt the variable direction, nullptr if not found
     */
    LNode *search(string);
    /**
     * \brief Close the actual escope
     */
    void Unscope();

    Scope *getActualScope() const;

    void setActualScope(Scope *actualScope);
};


#endif //PROYECTO_I_DII_C__MEMORYCONTROLLER_H
