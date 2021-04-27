//
// Created by isaac on 9/4/21.
//

#include <iostream>
#include "MemoryController.h"
#include "Gcollector.h"
#include <nlohmann/json.hpp>
#include "loggerS.h"


MemoryController *MemoryController:: self;


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
    if(ptr_actual!= nullptr){return;}
    MemoryController::ptr_start = ::operator new(100 * 1024 * sizeof(char));
    MemoryController::ptr_End = (char *) ptr_start + 100 * 1024 - 1;
    MemoryController::ptr_actual = ptr_start;
    MemoryController::Main_Scope = new Scope;
    MemoryController::Actual_Scope = Main_Scope;
}

void MemoryController::new_scope() {
    testing_scope();
    cout << "new scope" << endl;
    auto *scope = new Scope();
    LOG_INFO << "Creating new scope";
    Actual_Scope->setNextScope(scope);
    scope->setPreviousScope(scope);
    Actual_Scope = scope;
}

LNode *MemoryController::define_ints(const string &id) {
    testing_scope();
    if (Actual_Scope->Search(id) != nullptr) { return nullptr; }
    LOG_INFO<< "Creating a  type int";
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
    LOG_INFO<< "Creating a type string";
    testing_scope();
    if (Actual_Scope->Search(id) != nullptr) { return nullptr; }
    auto *node = new LNode("tag");
    node->setId(id);
    node->setValue((void *) new string("char"));
    Actual_Scope->getId()->setFirst(node);
    Gcollector *Garbage = new Gcollector;
    auto *node2 = Garbage->getChars();
    node2->setId(id);
    node2->setValue(ptr_actual);
    Actual_Scope->getChars()->setFirst(node2);
    return node2;
}

LNode *MemoryController::define_floats(string tag) {
    testing_scope();
    if (Actual_Scope->Search(tag) != nullptr) { return nullptr; }
    LOG_INFO<< "Creating a type floats";
    auto *node = new LNode("tag");
    node->setId(tag);
    node->setValue((void *) new string("float"));
    Actual_Scope->getId()->setFirst(node);
    Gcollector *Garbage = new Gcollector;
    auto *node2 = Garbage->getInts();
    node2->setId(tag);
    node2->setValue(ptr_actual);
    Actual_Scope->getFloats()->setFirst(node2);
    return node2;
}

/**
 * Redo to work as a scope or a uniq big list
 * @param tag
 */
LNode *MemoryController::define_structs(string tag) {
    testing_scope();
    return nullptr;
}

LNode *MemoryController::define_references(string tag) {
    testing_scope();
    if (Actual_Scope->Search(tag) != nullptr) { return nullptr; }
    LOG_INFO << "Creating a reference";
    auto *node = new LNode("tag");
    node->setId(tag);
    node->setValue((void *) new string("reference"));
    Actual_Scope->getId()->setFirst(node);

    Gcollector *Garbage = new Gcollector;
    auto *node2 = Garbage->getReferences();
    node2->setId(tag);
    node2->setValue(ptr_actual);
    Actual_Scope->getReferences()->setFirst(node2);
    return node2;
}

LNode *MemoryController::define_longs(string tag) {
    testing_scope();
    if (Actual_Scope->Search(tag) != nullptr) { return nullptr; }
    LOG_INFO<< "Creating a type long";
    auto *node = new LNode("tag");
    node->setId(tag);
    node->setValue((void *) new string("long"));
    Actual_Scope->getId()->setFirst(node);
    Gcollector *Garbage = new Gcollector;
    auto *node2 = Garbage->getLongs();
    node2->setId(tag);
    node2->setValue(ptr_actual);
    Actual_Scope->getLongs()->setFirst(node2);
    return node2;
}

LNode *MemoryController::define_doubles(string tag) {
    testing_scope();
    if (Actual_Scope->Search(tag) != nullptr) { return nullptr; }
    LOG_INFO << "Creating a type double";
    auto *node = new LNode("tag");
    node->setId(tag);
    node->setValue((void *) new string("double"));
    Actual_Scope->getId()->setFirst(node);
    Gcollector *Garbage = new Gcollector;
    auto *node2 = Garbage->getDoubles();
    node2->setId(tag);
    node2->setValue(ptr_actual);
    Actual_Scope->getDoubles()->setFirst(node2);
    return node2;
}

void MemoryController::testing_scope() {
    if (Actual_Scope == nullptr) {
        Actual_Scope == Main_Scope;
    }
}

void *MemoryController::getPtrActual() const {
    return ptr_actual;
}

void MemoryController::increment_ptr(size_t size) {
    ptr_actual = (char *) ptr_actual + size;
}

LNode * MemoryController::search(string tag) {
    LNode *founded = nullptr;
    Scope * Scope_search;
    Scope_search=Actual_Scope->Search(tag);
    string type= Scope_search->getType();
    if (type == "int") {
        founded= Scope_search->getInts()->getNode(tag);
    } else if (type == "char") {
        founded= Scope_search->getChars()->getNode(tag);
    } else if (type == "float") {
        founded= Scope_search->getFloats()->getNode(tag);
    } else if (type == "struct") {
        founded= Scope_search->getStructs()->getNode(tag);
    } else if (type == "reference") {
        founded= Scope_search->getReferences()->getNode(tag);
    } else if (type == "long") {
        founded= Scope_search->getLongs()->getNode(tag);
    } else if (type == "double") {
        founded= Scope_search->getDoubles()->getNode(tag);
    }
    if (founded== nullptr){return nullptr;}
    return founded;
}

Scope *MemoryController::getMainScope() const {
    return Main_Scope;
};



