//
// Created by isaac on 9/4/21.
//

#include "MemoryController.h"
MemoryController *MemoryController:: self;


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
}

void MemoryController::new_scope() {
    auto * scope=new Scope();
    Actual_Scope->setNextScope(scope);
    scope->setPreviousScope(scope);
    Actual_Scope=scope;
}

void MemoryController::define_ints(string id) {
    LNode * node= new LNode();
    node->setId(id);
    node->setValue((void *) "int");
    Actual_Scope->getId()->setFirst(node)
    LNode * node2= new LNode();


};


