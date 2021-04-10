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
    ::operator delete(a );
}

MemoryController::MemoryController() {
    MemoryController ::  ints=new Llist;
    MemoryController ::  longs= new Llist;
    MemoryController ::  chars= new Llist;
    MemoryController ::  floats= new Llist;
    MemoryController ::  doubles= new Llist;
    MemoryController ::  structs= new Llist;
    MemoryController ::  references= new Llist;
}
