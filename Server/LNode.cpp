//
// Created by isaac on 9/4/21.
//

#include "LNode.h"

const string &LNode::getId() const {
    return id;
}

void LNode::setId(const string &id) {
    LNode::id = id;
}

int LNode::getReferences() const {
    return references;
}

void LNode::setReferences(int references) {
    LNode::references = references;
}

void *LNode::getValue() const {
    return value;
}

void LNode::setValue(void *value) {
    LNode::value = value;
}

LNode *LNode::getNext() const {
    return next;
}

void LNode::setNext(LNode *next) {
    LNode::next = next;
}

string LNode::search(const string& tag) {
    if(id==tag){
        return *(string*)value;
    }
    else if (next== nullptr){
        return string() ;
    }
    return next->search(tag);
}


