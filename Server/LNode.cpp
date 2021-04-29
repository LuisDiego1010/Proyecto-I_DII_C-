//
// Created by isaac on 9/4/21.
//

#include "LNode.h"
#include "MemoryController.h"

const string &LNode::getId() const {
    return id;
}

void LNode::setId(const string &id) {
    LNode::id = id;
}

int LNode::getReferences() const {
    return references;
}

void LNode::setReferences(int references) {
    LNode::references += references;
}

void *LNode::getValue() const {
    return value;
}

void LNode::setValue(void *value) {
    LNode::value = value;
}

LNode *LNode::getNext() const {
    return next;
}

void LNode::setNext(LNode *next) {
    LNode::next = next;
}

string LNode::search(const string &tag) {
    if (id == tag) {
        return *(string *) value;
    } else if (next == nullptr) {
        return string();
    }
    return next->search(tag);
}

LNode::LNode(const string &type) {
    if (type == "tag") {
        return;
    }
    auto *memoryController = new MemoryController();
    this->value = memoryController->getPtrActual();
    this->references = 1;
    if (type == "int") {
        this->type_string="int";
        memoryController->increment_ptr(sizeof(int));
    } else if (type == "char") {
        this->type_string="char";
        memoryController->increment_ptr(sizeof(char));
    } else if (type == "float") {
        this->type_string="float";
        memoryController->increment_ptr(sizeof(float));
    } else if (type == "struct") {
        this->type_string="struct";
    } else if (type == "reference") {
        this->type_string="reference";
        int a;
        int& ref=a;
        memoryController->increment_ptr(sizeof(ref));
    } else if (type == "long") {
        this->type_string="long";
        memoryController->increment_ptr(sizeof(long));
    } else if (type == "double") {
        this->type_string="double";
        memoryController->increment_ptr(sizeof(double));
    }
}

void *LNode::operator new(std::size_t) {
    return nullptr;
}

void LNode::operator delete(void *node) {
}

const string &LNode::getTypeString() const {
    return type_string;
}

void LNode::setTypeString(const string &typeString) {
    type_string = typeString;
}

string LNode::getJson() {
    string JS;
    JS=JS+type_string;
    JS=JS+id+" ";
    if (type_string == "int") {
        int * Jsvalue= (int*) getValue();
        int *direction= reinterpret_cast<int *>(&Jsvalue);
        JS=JS+std::to_string(reinterpret_cast<int>(*direction))+" ";
        JS=JS+std::to_string(*Jsvalue);
    } else if (type_string == "char") {
        char * Jsvalue= (char*) getValue();
        int *direction= reinterpret_cast<int *>(&Jsvalue);
        JS=JS+std::to_string(reinterpret_cast<int>(*direction))+" ";
        JS=JS+std::to_string(*Jsvalue);
    } else if (type_string == "float") {
        float * Jsvalue= (float*) getValue();
        int *direction= reinterpret_cast<int *>(&Jsvalue);
        JS=JS+std::to_string(reinterpret_cast<int>(*direction))+" ";
        JS=JS+std::to_string(*Jsvalue);
    } else if (type_string == "struct") {
        Scope * Jsvalue= (Scope*) getValue();
        int *direction= reinterpret_cast<int *>(&Jsvalue);
        JS=JS+std::to_string(reinterpret_cast<int>(*direction))+" ";
        JS=JS+"\n"+Jsvalue->GetJson();
    } else if (type_string == "reference") {
        LNode * Jsvalue= (LNode*) getValue();
        int *direction= reinterpret_cast<int *>(&Jsvalue);
        JS=JS+std::to_string(reinterpret_cast<int>(*direction))+" ";
        JS=JS+Jsvalue->id;
    } else if (type_string == "long") {
        long * Jsvalue= (long*) getValue();
        int *direction= reinterpret_cast<int *>(&Jsvalue);
        JS=JS+std::to_string(reinterpret_cast<int>(*direction))+" ";
        JS=JS+std::to_string(*Jsvalue);
    } else if (type_string == "double") {
        double * Jsvalue= (double*) getValue();
        int *direction= reinterpret_cast<int *>(&Jsvalue);
        JS=JS+std::to_string(reinterpret_cast<int>(*direction))+" ";
        JS=JS+std::to_string(*Jsvalue);
    }
    JS= JS+" "+std::to_string(references);
    if(next== nullptr){
        return JS+"\n";
    }
    return JS+"\n"+next->getJson();
}



