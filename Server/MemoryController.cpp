//
// Created by isaac on 9/4/21.
//

#include "MemoryController.h"
MemoryController *MemoryController:: self;
string *MemoryController:: ints;
string *MemoryController:: chars;
string *MemoryController:: floats;
string *MemoryController::structs;
string *MemoryController:: references;
string *MemoryController:: longs;
string *MemoryController:: doubles;

void *MemoryController::operator new(std::size_t) {
    if(self== nullptr){
        self= :: new MemoryController;}
    return self;
}

void MemoryController::operator delete(void * a) {
    ::operator delete(a);
}

MemoryController::MemoryController() {
    MemoryController:: ptr_start= operator new(100*1024* sizeof(char)) ;
    MemoryController:: ptr_End=(char *)ptr_start+100*1024 -1;
    MemoryController:: ptr_actual=ptr_start;
    MemoryController:: Main_Scope=new Scope;
    MemoryController:: Actual_Scope=Main_Scope;
    *ints="int";
    *chars="char";
}

void MemoryController::new_scope() {
    auto * scope=new Scope();
    Actual_Scope->setNextScope(scope);
    scope->setPreviousScope(scope);
    Actual_Scope=scope;
}

void MemoryController::define_ints(const string& id) {
    auto * node= new LNode();
    node->setId(id);
    node->setValue((void*)ints);
    Actual_Scope->getId()->setFirst(node);
    auto * node2= new LNode();
    node2->setId(id);
    node2->setValue(ptr_actual);
    ptr_actual=(char *)ptr_actual+ sizeof(int);
    Actual_Scope->getInts()->setFirst(node2);

}

void MemoryController::define_chars(const string& id) {
    auto * node= new LNode();
    node->setId(id);
    node->setValue((void *) chars);
    Actual_Scope->getId()->setFirst(node);
    auto * node2= new LNode();
    node2->setId(id);
    node2->setValue(ptr_actual);
    ptr_actual=(char *)ptr_actual+ sizeof(char);
    Actual_Scope->getChars()->setFirst(node2);

};


