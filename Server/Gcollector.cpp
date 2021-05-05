//
// Created by isaac on 9/4/21.
//

#include <cstdio>
#include "Gcollector.h"

#include "LNode.h"
#include "Llist.h"
#include "Parser.h"
#include <boost/date_time.hpp>
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
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Request to GarbageCollector\n";
    }
    return garbarge;
}

void Gcollector::operator delete(void * a) {
    ::operator delete(a );
}

Gcollector::Gcollector() {
    if(ints!= nullptr && chars!= nullptr && Gcollector::garbarge!= nullptr){return;}
    Gcollector ::  ints=new Llist;
    Gcollector ::  longs= new Llist;
    Gcollector ::  chars= new Llist;
    Gcollector ::  floats= new Llist;
    Gcollector ::  doubles= new Llist;
    Gcollector ::  structs= new Llist;
    Gcollector ::  references= new Llist;
}

LNode *Gcollector::getInts() const {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Reusing the int data position\n";
    if(ints->getFirst()== nullptr){
        return ::new LNode("int");
    }else{
        LNode* tmp;
        tmp=ints->getFirst();
        ints->First=(tmp->getNext());
        tmp->setNext(nullptr);
        return tmp;
    }

}

void Gcollector::setInts(LNode *int_node) {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] The int data was deleted and is in the Collector\n";
    if(ints->getFirst()== nullptr){
        int_node->setNext(nullptr);
        ints->setFirst(int_node);
    }else{
        int_node->setNext(nullptr);
        ints->setFirst(int_node);
    }
}

LNode *Gcollector::getChars() const {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Reusing the char data position\n";
    if(chars->getFirst()== nullptr){
        return ::new LNode("char");
    }else{
        LNode* tmp;
        tmp=chars->getFirst();
        chars->First=(tmp->getNext());
        tmp->setNext(nullptr);
        return tmp;
    }
}

void Gcollector::setChars(LNode *char_node) {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] The char data was deleted and is in the Collector\n";
    if(chars->getFirst()== nullptr){
        chars->setFirst(char_node);
    }else{
        char_node->setNext(chars->getFirst());
        chars->setFirst(char_node);
    }
}

LNode *Gcollector::getFloats() const {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Reusing the float data position\n";
    if(floats->getFirst()== nullptr){
        return ::new LNode("float");
    }else{
        LNode* tmp;
        tmp=floats->getFirst();
        floats->First=(tmp->getNext());
        tmp->setNext(nullptr);
        return tmp;
    }
}

void Gcollector::setFloats(LNode *float_node) {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] The float data was deleted and is in the Collector\n";
    if(floats->getFirst()== nullptr){
        floats->setFirst(float_node);
    }else{
        floats->setFirst(float_node);
    }
}

LNode *Gcollector::getStructs() const {
    if(structs->getFirst()== nullptr){
        return ::new LNode("struct");
    }else{
        Parser::logg +=
                "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Reusing the struct position\n";
        LNode* tmp;
        tmp=structs->getFirst();
        structs->First=(tmp->getNext());
        tmp->setNext(nullptr);
        return tmp;
    }
}

void Gcollector::setStructs(LNode *struct_node) {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] The struct was deleted and is in the Collector\n";
    if(structs->getFirst()== nullptr){
        structs->setFirst(struct_node);
    }else{
        structs->setFirst(struct_node);
    }
}

LNode *Gcollector::getReferences() const {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Reusing the reference position\n";
    if(references->getFirst()== nullptr){
        return ::new LNode("reference");
    }else{
        LNode* tmp;
        tmp=references->getFirst();
        references->First=(tmp->getNext());
        tmp->setNext(nullptr);
        return tmp;
    }
}

void Gcollector::setReferences(LNode *reference_node) {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] The reference data was deleted and is in the Collector\n";
    if(references->getFirst()== nullptr){
        references->setFirst(reference_node);
    }else{
        references->setFirst(reference_node);
    }
}

LNode *Gcollector::getLongs() const {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Reusing the long data position\n";
    if(longs->getFirst()== nullptr){
        return ::new LNode("long");
    }else{
        LNode* tmp;
        tmp=longs->getFirst();
        longs->First=(tmp->getNext());
        tmp->setNext(nullptr);
        return tmp;
    }
}

void Gcollector::setLongs(LNode *long_node) {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] The longs data was deleted and is in the Collector\n";
    if(longs->getFirst()== nullptr){
        longs->setFirst(long_node);
    }else{
        longs->setFirst(long_node);
    }
}

LNode *Gcollector::getDoubles() const {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Reusing the double data position\n";
    if(doubles->getFirst()== nullptr){
        return ::new LNode("double");
    }else{
        LNode* tmp;
        tmp=doubles->getFirst();
        doubles->First=(tmp->getNext());
        tmp->setNext(nullptr);
        return tmp;
    }
}

void Gcollector::setDoubles(LNode *double_node) {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] The doubles data was deleted and is in the Collector\n";
    if(doubles->getFirst()== nullptr){
        doubles->setFirst(double_node);
    }else{
        doubles->setFirst(double_node);
    }
}
