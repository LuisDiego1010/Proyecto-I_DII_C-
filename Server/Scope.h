//
// Created by isaac on 10/4/21.
//

#ifndef PROYECTO_I_DII_C__SCOPE_H
#define PROYECTO_I_DII_C__SCOPE_H


#include "Llist.h"

using namespace std;

class Scope {
    string type;
    Llist * id;
public:
    const string &getType() const;

    Llist *getId() const;

public:
    void setType(const string &type);

    void setId(Llist *id);

    void setInts(Llist *ints);

    void setChars(Llist *chars);

    void setFloats(Llist *floats);

    void setStructs(Llist *structs);

    void setReferences(Llist *references);

    void setLongs(Llist *longs);

    void setDoubles(Llist *doubles);

private:
    Llist * ints;
    Llist * chars;
    Llist * floats;
    Llist * structs;
    Llist * references;
public:
    Llist *getInts() const;

    Llist *getChars() const;

    Llist *getFloats() const;

    Llist *getStructs() const;

    Llist *getReferences() const;

    Llist *getLongs() const;

    Llist *getDoubles() const;

private:
    Llist * longs;
    Llist * doubles;
    Scope * Next_Scope;
    Scope * Previous_Scope;
public:
    Scope *getNextScope() const;

    void setNextScope(Scope *nextScope);

    Scope *getPreviousScope() const;

    void setPreviousScope(Scope *previousScope);

public:
    Scope();
    /**
     * \brief brief int he actual scope and previous scopes for a variable
     * @return the scope where the variable is saved. Or nullptr if no founded.
     */
    Scope * Search(const string&);
    /**
     * \brief Create a string with the info of the Scope
     * @return
     */
    string GetJson();
    /**
     * Delete the scope and send element to reutilize.
     */
    void Delete();
};


#endif //PROYECTO_I_DII_C__SCOPE_H
