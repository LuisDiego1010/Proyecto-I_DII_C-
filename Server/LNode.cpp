//
// Created by isaac on 9/4/21.
//

#include "LNode.h"
#include "MemoryController.h"

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

LNode::LNode(const string& type) {
    if(type=="tag"){
        return;
    }
    auto* memoryController= new MemoryController();
    this->value=memoryController->getPtrActual();
    this->references=1;
    if(type=="int"){
        memoryController->increment_ptr(sizeof(int));
    }else if(type=="char"){
        memoryController->increment_ptr(sizeof(char));
    }else if(type=="float"){
        memoryController->increment_ptr(sizeof(float ));
    }else if(type=="struct"){

    }else if(type=="reference"){
        int a;
        int ref{a};
        memoryController->increment_ptr(sizeof(ref));
    }else if(type=="long"){
        memoryController->increment_ptr(sizeof(long));
    }else if(type=="double"){
        memoryController->increment_ptr(sizeof(double ));
    }
}

void *LNode::operator new(std::size_t) {
    return nullptr;
}

void LNode::operator delete(void * node) {
}


