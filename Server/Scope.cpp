//
// Created by isaac on 10/4/21.
//

#include "Scope.h"
#include "Gcollector.h"
#include "MemoryController.h"

#include <utility>

Scope::Scope() {
    Scope::type;
    Scope::id = new Llist;
    Scope::ints = new Llist;
    Scope::longs = new Llist;
    Scope::chars = new Llist;
    Scope::floats = new Llist;
    Scope::doubles = new Llist;
    Scope::structs = new Llist;
    Scope::references = new Llist;
    Scope::Next_Scope = nullptr;
    Scope::Previous_Scope = nullptr;
}

/**
 * \brief search for a value tag in the available Scopes
 * @param tag
 * @return ptr to the Scope where the the tag was founded, nullptr if not found
 */
Scope *Scope::Search(const string &tag) {

    string a;
    a = this->id->search(tag);
    if (!a.empty()) {
        type = a;
        return this;
    } else if (Previous_Scope == nullptr) {
        return nullptr;
    } else return Previous_Scope->Search(tag);
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
https://forum.qt.io/topic/15324/solved-updating-the-text-on-a-qlabel/2
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

string Scope::GetJson() {
    string JS;
    JS = JS + ints->LJson();
    JS = JS + doubles->LJson();
    JS = JS + floats->LJson();
    JS = JS + chars->LJson();
    JS = JS + structs->LJson();
    JS = JS + references->LJson();
    JS = JS + longs->LJson();
    if (getNextScope() == nullptr) {
        return JS;
    }
    return JS + getNextScope()->GetJson();
}

void Scope::Delete() {
    auto *collector = new Gcollector;
    //Code to complete struct creation
    if (getPreviousScope() != nullptr) {
        if (getPreviousScope()->getNextScope() == nullptr) {
            auto *memory = new MemoryController;
            memory->setActualScope(getPreviousScope());
            setPreviousScope(nullptr);
            return;
        }
    }
    //code to send all types in the scope to the garbage
    while (ints->getFirst() != nullptr) {
        collector->setInts(ints->getFirst());
        ints->setFirst(ints->getFirst()->getNext());
    }
    while (chars->getFirst() != nullptr) {
        collector->setChars(chars->getFirst());
        chars->setFirst(chars->getFirst()->getNext());
    }
    while (floats->getFirst() != nullptr) {
        collector->setFloats(floats->getFirst());
        floats->setFirst(floats->getFirst()->getNext());
    }
    while (doubles->getFirst() != nullptr) {
        collector->setDoubles(doubles->getFirst());
        doubles->setFirst(doubles->getFirst()->getNext());
    }
    while (longs->getFirst() != nullptr) {
        collector->setLongs(longs->getFirst());
        longs->setFirst(longs->getFirst()->getNext());
    }
    while (references->getFirst() != nullptr) {
        collector->setReferences(references->getFirst());
        references->setFirst(references->getFirst()->getNext());
    }
    while (structs->getFirst() != nullptr) {
        Scope *tmp = (Scope *) structs->getFirst()->getValue();
        references->setFirst(references->getFirst()->getNext());
        tmp->Delete();
    }

}



