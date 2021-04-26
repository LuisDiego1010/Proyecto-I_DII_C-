//
// Created by isaac on 9/4/21.
//

#ifndef PROYECTO_I_DII_C__LLIST_H
#define PROYECTO_I_DII_C__LLIST_H


#include "LNode.h"

class Llist {
    LNode *First;
public:
    Llist();

    LNode *getFirst() const;

    void setFirst(LNode *first);

    string search(const string &id);

    LNode *getNode(string);

    string LJson();
};


#endif //PROYECTO_I_DII_C__LLIST_H
