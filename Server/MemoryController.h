//
// Created by isaac on 9/4/21.
//

#ifndef PROYECTO_I_DII_C__MEMORYCONTROLLER_H
#define PROYECTO_I_DII_C__MEMORYCONTROLLER_H

#include <cstdio>
#include "Llist.h"
#include "Scope.h"
#include "string.h"

using namespace std;
/**
 * @class Control the memory of the client, Use Linked list to storage metadata and ptr to the data.
 */
class MemoryController {
    static string *ints;
    static string *chars;
    static string *floats;
    static string *structs;
    static string *references;
    static string *longs;
    static string *doubles;
    static MemoryController* self;
    /**
     * Start of the memory block
     */
    void* ptr_start{};
    /**
     * End of  the memory block
     */
    void* ptr_End{};
    /**
     * ptr in the actual free to use scope
     */
    void* ptr_actual{};
    /**
     * Scope to do a delete and delete all
     */
    Scope* Main_Scope{};
    /**
     * Scope to work
     */
    Scope* Actual_Scope{};



public:
    void* operator new(std::size_t);
    void operator delete(void*) ;
    MemoryController();

    /**
     * Create a new scope and replace the actual scope whit it
     */
    void new_scope();
    /**
     * Insert a new int in the actual scope
     */
    void define_ints(const string&);
    /**
     * Insert a new char in the actual scope
     */
    void define_chars(const string&);
    /**
     * Insert a new  Float in the actual scope
     */
    void define_floats(string);
    /**
     * start to create a structure
     */
    void define_structs(string);
    /**
     * Insert a new reference in the actual scope
     */
    void define_references(string);
    /**
     * Insert a new long in the actual scope
     */
    void define_longs(string);
    /**
     * Insert a double in the actual scope
     */
    void define_doubles();

};


#endif //PROYECTO_I_DII_C__MEMORYCONTROLLER_H
