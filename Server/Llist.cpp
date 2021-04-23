//
// Created by isaac on 9/4/21.
//

#include "Llist.h"
#include "Gcollector.h"

/**
 * \brief Recursive function that search for a tag and return the type of the variable with this tag
 * @param id
 * @return String with the type.
 */
string Llist::search(const string &id) {
    if (First == nullptr) {
        return string();
    }
    return First->search(id);
}

LNode *Llist::getFirst() const {
    return First;
}

/**
 * \brief place a LNode in the first position
 * @param first
 */
void Llist::setFirst(LNode *first) {
    if (First != nullptr) {
        first->setNext(First);
        First = first;
    } else {
        First = first;
    }
}

Llist::Llist() {
    First = nullptr;
}

/**
 * \brief Get the Node wher a Tag was founded
 * @param tag
 * @return the LNode whith the equal tag, nullptr if not LNode
 */
LNode *Llist::getNode(string tag) {
    if (First == nullptr) { return nullptr; }
    LNode *actual = First;
    while (actual->getNext() != nullptr) {
        if (actual->getId() == tag) {
            return actual;
        }
        actual = actual->getNext();
    }
}
