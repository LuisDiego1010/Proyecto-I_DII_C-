//
// Created by isaac on 9/4/21.
//

#ifndef PROYECTO_I_DII_C__LLIST_H
#define PROYECTO_I_DII_C__LLIST_H


#include "LNode.h"
#include "Gcollector.h"

class Llist {
 LNode * First;
public:
    LNode *getFirst() const;

    void setFirst(LNode *first);

    string search(const string& id);
private:
    Gcollector* garbarge= new Gcollector;

};


#endif //PROYECTO_I_DII_C__LLIST_H
