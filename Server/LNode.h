//
// Created by isaac on 9/4/21.
//

#ifndef PROYECTO_I_DII_C__LNODE_H
#define PROYECTO_I_DII_C__LNODE_H

#include <string>

using namespace std;
/**
 * @class Linked list Node, storage the id, #references, a ptr to the value and the ptr of the next Node.
 * @value is a void ptr that need to be casted to the specific type after get out of the List.
 */
class LNode {
    string id;
    int references;
    void* value;
    string type_string;
    LNode* next;
public:
    LNode(const string&);
    const string &getId() const;

    void setId(const string &id);

    int getReferences() const;

    void setReferences(int references);

    void *getValue() const;

    void setValue(void *value);

    LNode *getNext() const;

    void setNext(LNode *next);
    /**
     * \brief Recursive function that search for a tag
     * @param tag
     * @return the type of the variable as a string
     */
    string search(const string& );

    const string &getTypeString() const;

    void setTypeString(const string &typeString);

    void* operator new(std::size_t);
    void operator delete(void*);
};


#endif //PROYECTO_I_DII_C__LNODE_H
