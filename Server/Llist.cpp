//
// Created by isaac on 9/4/21.
//

#include "Llist.h"

const LNode &Llist::getFirst() const {
    return First;
}

void Llist::setFirst(const LNode &first) {
    First = first;
}
