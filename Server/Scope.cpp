//
// Created by isaac on 10/4/21.
//

#include "Scope.h"

#include <utility>

Scope::Scope() {
    Scope ::  type;
    Scope ::  id=new Llist;
    Scope ::  ints=new Llist;
    Scope ::  longs= new Llist;
    Scope ::  chars= new Llist;
    Scope ::  floats= new Llist;
    Scope ::  doubles= new Llist;
    Scope ::  structs= new Llist;
    Scope ::  references= new Llist;
    Scope ::  Next_Scope;
    Scope ::  Previous_Scope;
}

Scope * Scope::Search(const string& tag) {
    string a;
    a=this->id->search(tag);
    if(!a.empty()) {
        type=a;
        return this;
    }
    else return Previous_Scope->Search(tag) ;
}

Scope *Scope::getNextScope() const {
    return Next_Scope;
}

void Scope::setNextScope(Scope *nextScope) {
    Next_Scope = nextScope;
}

Scope *Scope::getPreviousScope() const {
    return Previous_Scope;
}

void Scope::setPreviousScope(Scope *previousScope) {
    Previous_Scope = previousScope;
}

void Scope::setType(const string &type) {
    Scope::type = type;
}

void Scope::setId(Llist *id) {
    Scope::id = id;
}

void Scope::setInts(Llist *ints) {
    Scope::ints = ints;
}

void Scope::setChars(Llist *chars) {
    Scope::chars = chars;
}

void Scope::setFloats(Llist *floats) {
    Scope::floats = floats;
}

void Scope::setStructs(Llist *structs) {
    Scope::structs = structs;
}

void Scope::setReferences(Llist *references) {
    Scope::references = references;
}

void Scope::setLongs(Llist *longs) {
    Scope::longs = longs;
}

void Scope::setDoubles(Llist *doubles) {
    Scope::doubles = doubles;
}

const string &Scope::getType() const {
    return type;
}

Llist *Scope::getId() const {
    return id;
}

Llist *Scope::getInts() const {
    return ints;
}

Llist *Scope::getChars() const {
    return chars;
}

Llist *Scope::getFloats() const {
    return floats;
}

Llist *Scope::getStructs() const {
    return structs;
}

Llist *Scope::getReferences() const {
    return references;
}

Llist *Scope::getLongs() const {
    return longs;
}

Llist *Scope::getDoubles() const {
    return doubles;
}



