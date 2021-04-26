//
// Created by isaac on 9/4/21.
//

#include <cstdio>
#include "Gcollector.h"

#include "LNode.h"
#include "Llist.h"
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/core.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/global_logger_storage.hpp>

using namespace std;

Gcollector *Gcollector:: garbarge;

void *Gcollector::operator new(std::size_t) {
    if(garbarge== nullptr){
    garbarge= :: new Gcollector;
    BOOST_LOG_TRIVIAL(info) << "Creating a  GarbageCollector";
    }
    return garbarge;
}

void Gcollector::operator delete(void * a) {
    ::operator delete(a );
}

Gcollector::Gcollector() {
    if(ints!= nullptr & chars!= nullptr){return;}
    Gcollector ::  ints=new Llist;
    Gcollector ::  longs= new Llist;
    Gcollector ::  chars= new Llist;
    Gcollector ::  floats= new Llist;
    Gcollector ::  doubles= new Llist;
    Gcollector ::  structs= new Llist;
    Gcollector ::  references= new Llist;
}

LNode *Gcollector::getInts() const {
    BOOST_LOG_TRIVIAL(info) << "Reusing the int data position";
    if(ints->getFirst()== nullptr){
        return ::new LNode("int");
    }else{
        LNode* tmp;
        tmp=ints->getFirst();
        ints->setFirst(tmp->getNext());
        return tmp;
    }

}

void Gcollector::setInts(LNode *int_node) {
    BOOST_LOG_TRIVIAL(info) << "The int data was deleted and is in the Collector";
    if(ints->getFirst()== nullptr){
        ints->setFirst(int_node);
    }else{
        int_node->setNext(ints->getFirst());
        doubles->setFirst(int_node);
    }
}

LNode *Gcollector::getChars() const {
    BOOST_LOG_TRIVIAL(info) << "Reusing the char data position";
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
    BOOST_LOG_TRIVIAL(info) << "The char data was deleted and is in the Collector";
    if(chars->getFirst()== nullptr){
        chars->setFirst(char_node);
    }else{
        char_node->setNext(chars->getFirst());
        doubles->setFirst(char_node);
    }
}

LNode *Gcollector::getFloats() const {
    BOOST_LOG_TRIVIAL(info) << "Reusing the float data position";
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
    BOOST_LOG_TRIVIAL(info) << "The float data was deleted and is in the Collector";
    if(floats->getFirst()== nullptr){
        floats->setFirst(float_node);
    }else{
        float_node->setNext(floats->getFirst());
        doubles->setFirst(float_node);
    }
}

LNode *Gcollector::getStructs() const {
    BOOST_LOG_TRIVIAL(info) << "Reusing the struct position";
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
    BOOST_LOG_TRIVIAL(info) << "The struct was deleted and is in the Collector";
    if(structs->getFirst()== nullptr){
        structs->setFirst(struct_node);
    }else{
        struct_node->setNext(structs->getFirst());
        structs->setFirst(struct_node);
    }
}

LNode *Gcollector::getReferences() const {
    BOOST_LOG_TRIVIAL(info) << "Reusing the reference position";
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
    BOOST_LOG_TRIVIAL(info) << "The reference data was deleted and is in the Collector";
    if(references->getFirst()== nullptr){
        references->setFirst(reference_node);
    }else{
        reference_node->setNext(references->getFirst());
        references->setFirst(reference_node);
    }
}

LNode *Gcollector::getLongs() const {
    BOOST_LOG_TRIVIAL(info) << "Reusing the long data position";
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
    BOOST_LOG_TRIVIAL(info) << "The longs data was deleted and is in the Collector";
    if(longs->getFirst()== nullptr){
        longs->setFirst(long_node);
    }else{
        long_node->setNext(longs->getFirst());
        longs->setFirst(long_node);
    }
}

LNode *Gcollector::getDoubles() const {
    BOOST_LOG_TRIVIAL(info) << "Reusing the double data position";
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
    BOOST_LOG_TRIVIAL(info) << "The doubles data was deleted and is in the Collector";
    if(doubles->getFirst()== nullptr){
        doubles->setFirst(double_node);
    }else{
        double_node->setNext(doubles->getFirst());
        doubles->setFirst(double_node);
    }
}
