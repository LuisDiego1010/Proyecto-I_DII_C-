//
// Created by isaac on 9/4/21.
//

#include <iostream>
#include "MemoryController.h"
#include "Gcollector.h"
#include "Parser.h"
#include <boost/date_time.hpp>
#include <nlohmann/json.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/core.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/global_logger_storage.hpp>

MemoryController *MemoryController::self;
int MemoryController::size;


void *MemoryController::operator new(std::size_t) {
    if (self == nullptr) {
        self = ::new MemoryController;
    }
    return self;
}

void MemoryController::operator delete(void *a) {
    ::operator delete(a);
}

MemoryController::MemoryController() {
    if (ptr_actual != nullptr) { return; }
    MemoryController::ptr_start = ::operator new(size * 1024 * sizeof(char));
    MemoryController::ptr_End = (char *) ptr_start + 100 * 1024 - 1;
    MemoryController::ptr_actual = ptr_start;
    MemoryController::Main_Scope = new Scope;
    MemoryController::Actual_Scope = Main_Scope;
}

void MemoryController::new_scope() {
    testing_scope();
    cout << "new scope" << endl;
    auto *scope = new Scope();
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Creating a scope\n";
    BOOST_LOG_TRIVIAL(info) << "Creating new scope";
    Actual_Scope = scope;
}

LNode *MemoryController::define_ints(const string &id) {
    testing_scope();
    if (Actual_Scope->Search(id) != nullptr) { return nullptr; }
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Creating a int\n";
    BOOST_LOG_TRIVIAL(info) << "Creating a  type int";
    auto *node = ::new LNode("tag");
    node->setId(id);
    node->setValue((void *) new string("int"));
    Actual_Scope->getId()->setFirst(node);

    Gcollector *Garbage = new Gcollector;
    auto *node2 = Garbage->getInts(); //pedirselo al garbage
    node2->setId(id);
    Actual_Scope->getInts()->setFirst(node2);
    return node2;
}

LNode *MemoryController::define_chars(const string &id) {
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Creating a string\n";
    BOOST_LOG_TRIVIAL(info) << "Creating a type string";
    testing_scope();
    if (Actual_Scope->Search(id) != nullptr) { return nullptr; }
    auto *node = ::new LNode("tag");
    node->setId(id);
    node->setValue((void *) new string("char"));
    Actual_Scope->getId()->setFirst(node);
    Gcollector *Garbage = new Gcollector;
    auto *node2 = Garbage->getChars();
    node2->setId(id);
    Actual_Scope->getChars()->setFirst(node2);
    return node2;
}

LNode *MemoryController::define_floats(string tag) {
    testing_scope();
    if (Actual_Scope->Search(tag) != nullptr) { return nullptr; }
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Creating a float\n";
    BOOST_LOG_TRIVIAL(info) << "Creating a type floats";
    auto *node = ::new LNode("tag");
    node->setId(tag);
    node->setValue((void *) new string("float"));
    Actual_Scope->getId()->setFirst(node);
    Gcollector *Garbage = new Gcollector;
    auto *node2 = Garbage->getFloats();
    node2->setId(tag);
    Actual_Scope->getFloats()->setFirst(node2);
    return node2;
}

/**
 * Redo to work as a scope or a uniq big list
 * @param tag
 */
LNode *MemoryController::define_structs(string tag) {
    testing_scope();
    if (Actual_Scope->Search(tag) != nullptr) { return nullptr; }
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Creating a struct\n";
    BOOST_LOG_TRIVIAL(info) << "Define a struct";
    auto *node = ::new LNode("tag");
    node->setId(tag);
    node->setValue((void *) new string("struct"));
    Actual_Scope->getId()->setFirst(node);

    auto *Garbage = new Gcollector;
    auto *node2 = Garbage->getStructs();
    node2->setId(tag);
    auto *structure = new Scope();
    node2->setValue(structure);
    Actual_Scope->getStructs()->setFirst(node2);
    structure->setPreviousScope(Actual_Scope);
    Actual_Scope=structure;
    return node2;
}

LNode *MemoryController::define_references(string tag) {
    testing_scope();
    if (Actual_Scope->Search(tag) != nullptr) { return nullptr; }
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Creating a reference\n";

    BOOST_LOG_TRIVIAL(info) << "Creating a reference";
    auto *node = ::new LNode("tag");
    node->setId(tag);
    node->setValue((void *) new string("reference"));
    Actual_Scope->getId()->setFirst(node);

    Gcollector *Garbage = new Gcollector;
    auto *node2 = Garbage->getReferences();
    node2->setId(tag);
    Actual_Scope->getReferences()->setFirst(node2);
    return node2;
}

LNode *MemoryController::define_longs(string tag) {
    testing_scope();
    if (Actual_Scope->Search(tag) != nullptr) { return nullptr; }
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Creating a long\n";
    BOOST_LOG_TRIVIAL(info) << "Creating a type long";
    auto *node = ::new LNode("tag");
    node->setId(tag);
    node->setValue((void *) new string("long"));
    Actual_Scope->getId()->setFirst(node);
    Gcollector *Garbage = new Gcollector;
    auto *node2 = Garbage->getLongs();
    node2->setId(tag);
    Actual_Scope->getLongs()->setFirst(node2);
    return node2;
}

LNode *MemoryController::define_doubles(string tag) {
    testing_scope();
    if (Actual_Scope->Search(tag) != nullptr) { return nullptr; }
    Parser::logg +=
            "[" + to_simple_string(boost::posix_time::second_clock::local_time()) + "] Creating a double\n";
    BOOST_LOG_TRIVIAL(info) << "Creating a type double";
    auto *node = :: new LNode("tag");
    node->setId(tag);
    node->setValue((void *) new string("double"));
    Actual_Scope->getId()->setFirst(node);
    Gcollector *Garbage = new Gcollector;
    auto *node2 = Garbage->getDoubles();
    node2->setId(tag);
    Actual_Scope->getDoubles()->setFirst(node2);
    return node2;
}

void MemoryController::testing_scope() {
    if (Actual_Scope == nullptr) {
        Actual_Scope = Main_Scope;
    }
}

void *MemoryController::getPtrActual() const {
    return ptr_actual;
}

void MemoryController::increment_ptr(size_t size) {
    ptr_actual = (char *) ptr_actual + size;
}

LNode *MemoryController::search(string tag) {
    LNode *founded = nullptr;
    Scope *Scope_search;
    Scope_search = Actual_Scope->Search(tag);
    if(Scope_search== nullptr){
        return nullptr;
    }
    string type = Scope_search->getType();
    if (type == "int") {
        founded = Scope_search->getInts()->getNode(tag);
    } else if (type == "char") {
        founded = Scope_search->getChars()->getNode(tag);
    } else if (type == "float") {
        founded = Scope_search->getFloats()->getNode(tag);
    } else if (type == "struct") {
        founded = Scope_search->getStructs()->getNode(tag);
    } else if (type == "reference") {
        founded = Scope_search->getReferences()->getNode(tag);
    } else if (type == "long") {
        founded = Scope_search->getLongs()->getNode(tag);
    } else if (type == "double") {
        founded = Scope_search->getDoubles()->getNode(tag);
    }
    if (founded == nullptr) { return nullptr; }
    return founded;
}

Scope *MemoryController::getMainScope() const {
    return Main_Scope;
}

void MemoryController::Unscope() {
    Scope *tmp;
    tmp = Actual_Scope;
    if (Actual_Scope == Main_Scope) {
        return;
    }
    if (Actual_Scope->getPreviousScope()== nullptr && Actual_Scope!=Main_Scope){
        Actual_Scope=Parser::GetLastScope();
    }
    Actual_Scope = Actual_Scope->getPreviousScope();
    Actual_Scope->setNextScope(nullptr);
    tmp->Delete();
    delete tmp;
}

Scope *MemoryController::getActualScope() const {
    return Actual_Scope;
}

void MemoryController::setActualScope(Scope *actualScope) {
    Actual_Scope = actualScope;
}

void MemoryController::Reset() {
    while(getMainScope()!=Actual_Scope){
        Scope* tmp= Actual_Scope;
        Actual_Scope=Actual_Scope->getPreviousScope();
        tmp->Delete();
        ::delete tmp;
    }
    Scope* tmp=Actual_Scope;
    Main_Scope=new Scope;
    Actual_Scope= nullptr;
    testing_scope();
    tmp->Delete();


 };



