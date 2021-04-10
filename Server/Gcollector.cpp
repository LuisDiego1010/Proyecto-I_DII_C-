//
// Created by isaac on 9/4/21.
//

#include <cstdio>
#include "Gcollector.h"

using namespace std;

Gcollector *Gcollector:: garbarge;

void *Gcollector::operator new(std::size_t) {
    if(garbarge== nullptr){
    garbarge= :: new Gcollector;}
    return garbarge;
}

void Gcollector::operator delete(void * a) {
    ::operator delete(a );
}

const LNode &Gcollector::getFirst() const {
    return First;
}

void Gcollector::setFirst(const LNode &first) {
    First = first;
}
