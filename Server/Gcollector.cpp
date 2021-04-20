//
// Created by isaac on 9/4/21.
//

#include <cstdio>
#include "Gcollector.h"

#include "LNode.h"
#include "Llist.h"

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

Gcollector::Gcollector() {
    Gcollector ::  ints=new Llist;
    Gcollector ::  longs= new Llist;
    Gcollector ::  chars= new Llist;
    Gcollector ::  floats= new Llist;
    Gcollector ::  doubles= new Llist;
    Gcollector ::  structs= new Llist;
    Gcollector ::  references= new Llist;
}

LNode *Gcollector::getInts() const {
    if(ints->getFirst()== nullptr){
        return new LNode("int");
    }else{
        LNode* tmp;
        tmp=ints->getFirst();
        ints->setFirst(tmp->getNext());
        return tmp;
    }

}

void Gcollector::setInts(LNode *int_node) {
    if(ints->getFirst()== nullptr){
        ints->setFirst(int_node);
    }else{
        int_node->setNext(ints->getFirst());
        doubles->setFirst(int_node);
    }
}

LNode *Gcollector::getChars() const {
    if(chars->getFirst()== nullptr){
        return new LNode("char");
    }else{
        LNode* tmp;
        tmp=chars->getFirst();
        chars->setFirst(tmp->getNext());
        return tmp;
    }
}

void Gcollector::setChars(LNode *char_node) {
    if(chars->getFirst()== nullptr){
        chars->setFirst(char_node);
    }else{
        char_node->setNext(chars->getFirst());
        doubles->setFirst(char_node);
    }
}

LNode *Gcollector::getFloats() const {
    if(floats->getFirst()== nullptr){
        return new LNode("float");
    }else{
        LNode* tmp;
        tmp=floats->getFirst();
        floats->setFirst(tmp->getNext());
        return tmp;
    }
}

void Gcollector::setFloats(LNode *float_node) {
    if(floats->getFirst()== nullptr){
        floats->setFirst(float_node);
    }else{
        float_node->setNext(floats->getFirst());
        doubles->setFirst(float_node);
    }
}

LNode *Gcollector::getStructs() const {
    if(structs->getFirst()== nullptr){
        return new LNode("struct");
    }else{
        LNode* tmp;
        tmp=structs->getFirst();
        structs->setFirst(tmp->getNext());
        return tmp;
    }
}

void Gcollector::setStructs(LNode *struct_node) {
    if(structs->getFirst()== nullptr){
        structs->setFirst(struct_node);
    }else{
        struct_node->setNext(structs->getFirst());
        structs->setFirst(struct_node);
    }
}

LNode *Gcollector::getReferences() const {
    if(references->getFirst()== nullptr){
        return new LNode("reference");
    }else{
        LNode* tmp;
        tmp=references->getFirst();
        references->setFirst(tmp->getNext());
        return tmp;
    }
}

void Gcollector::setReferences(LNode *reference_node) {
    if(references->getFirst()== nullptr){
        references->setFirst(reference_node);
    }else{
        reference_node->setNext(references->getFirst());
        references->setFirst(reference_node);
    }
}

LNode *Gcollector::getLongs() const {
    if(longs->getFirst()== nullptr){
        return new LNode("long");
    }else{
        LNode* tmp;
        tmp=longs->getFirst();
        longs->setFirst(tmp->getNext());
        return tmp;
    }
}

void Gcollector::setLongs(LNode *long_node) {
    if(longs->getFirst()== nullptr){
        longs->setFirst(long_node);
    }else{
        long_node->setNext(longs->getFirst());
        longs->setFirst(long_node);
    }
}

LNode *Gcollector::getDoubles() const {
    if(doubles->getFirst()== nullptr){
        return new LNode("double");
    }else{
        LNode* tmp;
        tmp=doubles->getFirst();
        doubles->setFirst(tmp->getNext());
        return tmp;
    }
}

void Gcollector::setDoubles(LNode *double_node) {
    if(doubles->getFirst()== nullptr){
        doubles->setFirst(double_node);
    }else{
        double_node->setNext(doubles->getFirst());
        doubles->setFirst(double_node);
    }
}
