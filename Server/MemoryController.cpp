//
// Created by isaac on 9/4/21.
//

#include <iostream>
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
    MemoryController:: ptr_start= ::operator new(100*1024* sizeof(char)) ;
    MemoryController:: ptr_End=(char *)ptr_start+100*1024 -1;
    MemoryController:: ptr_actual=ptr_start;
    MemoryController:: Main_Scope=new Scope;
    MemoryController:: Actual_Scope=Main_Scope;
}

void MemoryController::new_scope() {
    cout<<"new scope"<<endl;
    auto * scope=new Scope();
    testing_scope();
    Actual_Scope->setNextScope(scope);
    scope->setPreviousScope(scope);
    Actual_Scope=scope;
}

void MemoryController::define_ints(const string& id) {
    auto * node= new LNode();
    node->setId(id);
    node->setValue((void*)new string("int"));
    testing_scope();
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
    node->setValue((void *) new string("char"));
    testing_scope();
    Actual_Scope->getId()->setFirst(node);
    auto * node2= new LNode();
    node2->setId(id);
    node2->setValue(ptr_actual);
    ptr_actual=(char *)ptr_actual+ sizeof(char);
    Actual_Scope->getChars()->setFirst(node2);

}

void MemoryController::define_floats(string tag) {
    auto * node= new LNode();
    node->setId(tag);
    node->setValue((void *) new string("float"));
    testing_scope();
    Actual_Scope->getId()->setFirst(node);
    auto * node2= new LNode();
    node2->setId(tag);
    node2->setValue(ptr_actual);
    ptr_actual=(char *)ptr_actual+ sizeof(float );
    Actual_Scope->getFloats()->setFirst(node2);

}
/**
 * Redo to work as a scope or a uniq big list
 * @param tag
 */
void MemoryController::define_structs(string tag) {
    testing_scope();
}

void MemoryController::define_references(string tag) {
    auto * node= new LNode();
    node->setId(tag);
    node->setValue((void *) new string("reference"));
    testing_scope();
    Actual_Scope->getId()->setFirst(node);
    auto * node2= new LNode();
    node2->setId(tag);
    node2->setValue(ptr_actual);
    ptr_actual=(char *)ptr_actual+ 4*sizeof(char);
    Actual_Scope->getReferences()->setFirst(node2);

}

void MemoryController::define_longs(string tag) {
    auto * node= new LNode();
    node->setId(tag);
    node->setValue((void *) new string("long"));
    testing_scope();
    Actual_Scope->getId()->setFirst(node);
    auto * node2= new LNode();
    node2->setId(tag);
    node2->setValue(ptr_actual);
    ptr_actual=(char *)ptr_actual+ sizeof(long);
    Actual_Scope->getLongs()->setFirst(node2);

}

void MemoryController::define_doubles(string tag) {
    auto * node= new LNode();
    node->setId(tag);
    node->setValue((void *) new string("double"));
    testing_scope();
    Actual_Scope->getId()->setFirst(node);
    auto * node2= new LNode();
    node2->setId(tag);
    node2->setValue(ptr_actual);
    ptr_actual=(char *)ptr_actual+ sizeof(double);
    Actual_Scope->getDoubles()->setFirst(node2);

}

void MemoryController::testing_scope() {
    if(Actual_Scope== nullptr){
        Actual_Scope==Main_Scope;
    }
};


