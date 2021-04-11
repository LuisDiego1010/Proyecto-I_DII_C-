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
    LNode* next;
public:
    const string &getId() const;

    void setId(const string &id);

    int getReferences() const;

    void setReferences(int references);

    void *getValue() const;

    void setValue(void *value);

    LNode *getNext() const;

    void setNext(LNode *next);
    string search(const string& );
};


#endif //PROYECTO_I_DII_C__LNODE_H
