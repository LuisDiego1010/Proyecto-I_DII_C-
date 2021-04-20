//
// Created by isaac on 9/4/21.
//

#ifndef PROYECTO_I_DII_C__GCOLLECTOR_H
#define PROYECTO_I_DII_C__GCOLLECTOR_H

#include "LNode.h"
#include "Llist.h"

using namespace std;

class Gcollector {
public:
    Llist * ints;
    Llist * chars;
    Llist * floats;
    Llist * structs;
    Llist * references;
    Llist * longs;
    Llist * doubles;

public:

    static Gcollector* garbarge;


public:
    Gcollector();
   void* operator new(std::size_t);
   void operator delete(void*) ;

    LNode *getInts() const;

    void setInts(LNode *ints);

    LNode *getChars() const;

    void setChars(LNode *chars);

    LNode * getFloats() const;

    void setFloats(LNode *floats);

    LNode *getStructs() const;

    void setStructs(LNode *structs);

    LNode *getReferences() const;

    void setReferences(LNode *references);

    LNode *getLongs() const;

    void setLongs(LNode *longs);

    LNode *getDoubles() const;

    void setDoubles(LNode *doubles);
};


#endif //PROYECTO_I_DII_C__GCOLLECTOR_H
