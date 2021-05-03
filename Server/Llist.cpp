//
// Created by isaac on 9/4/21.
//

#include "Llist.h"
#include "Gcollector.h"


string Llist::search(const string &id) {
    if (First == nullptr) {
        return string();
    }
    return First->search(id);
}

LNode *Llist::getFirst() const {
    return First;
}


void Llist::setFirst(LNode *toadd) {
    if(toadd== nullptr){
        First=toadd;
    }
    if (First != nullptr) {
        toadd->setNext(First);
        First = toadd;
    } else {
        First = toadd;
    }
}

Llist::Llist() {
    First = nullptr;
}


LNode *Llist::getNode(string tag) {
    if (First == nullptr) { return nullptr; }
    LNode *actual = First;
    while (actual->getNext() != nullptr) {
        if (actual->getId() == tag) {
            return actual;
        }
        actual = actual->getNext();
    }
    return actual;
}

string Llist::LJson() {
    string JS;
    if (First== nullptr){
        return JS;
    }
    JS= First->getJson();
    return JS;
}
