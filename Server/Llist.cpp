//
// Created by isaac on 9/4/21.
//

#include "Llist.h"

string Llist::search(const string& id) {
    if(First == nullptr){
        return string ();
    }
    return First->search(id);
}

LNode *Llist::getFirst() const {
    return First;
}

void Llist::setFirst(LNode *first) {
    if (First!= nullptr){
        first->setNext(First);
        First=first;
    }else{
        First = first;
    }
}
