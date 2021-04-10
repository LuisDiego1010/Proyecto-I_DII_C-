//
// Created by isaac on 9/4/21.
//

#ifndef PROYECTO_I_DII_C__GCOLLECTOR_H
#define PROYECTO_I_DII_C__GCOLLECTOR_H


#include "LNode.h"

class Gcollector {
    LNode First;
public:
    const LNode &getFirst() const;

    void setFirst(const LNode &first);

    static Gcollector* garbarge;


public:
   void* operator new(std::size_t);
   void operator delete(void*) ;

};


#endif //PROYECTO_I_DII_C__GCOLLECTOR_H
