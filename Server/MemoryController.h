//
// Created by isaac on 9/4/21.
//

#ifndef PROYECTO_I_DII_C__MEMORYCONTROLLER_H
#define PROYECTO_I_DII_C__MEMORYCONTROLLER_H

#include <cstdio>
#include "Llist.h"

using namespace std;

class MemoryController {
    static MemoryController* self;
    Llist * ints;
    Llist * longs;
    Llist * chars;
    Llist * floats;
    Llist * doubles;
    Llist * structs;
    Llist * references;

public:
    void* operator new(std::size_t);

    void operator delete(void*) ;
    MemoryController();
};


#endif //PROYECTO_I_DII_C__MEMORYCONTROLLER_H
