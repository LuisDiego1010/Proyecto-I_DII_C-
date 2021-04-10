//
// Created by isaac on 9/4/21.
//

#ifndef PROYECTO_I_DII_C__LLIST_H
#define PROYECTO_I_DII_C__LLIST_H


#include "LNode.h"
#include "Gcollector.h"

class Llist {
 LNode First;
public:
    const LNode &getFirst() const;

    void setFirst(const LNode &first);

private:
    Gcollector* garbarge= new Gcollector;

};


#endif //PROYECTO_I_DII_C__LLIST_H
