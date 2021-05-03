//
// Created by isaac on 9/4/21.
//

#ifndef PROYECTO_I_DII_C__LLIST_H
#define PROYECTO_I_DII_C__LLIST_H


#include "LNode.h"

/**
 * \brief Container and operating class, linked list FIFO.
 */
class Llist {
public:
    LNode *First;

    Llist();

    LNode *getFirst() const;

    /**
     * \brief place a LNode in the first position
     * @param first
     */
    void setFirst(LNode *first);

    /**
     * \brief Recursive function that search for a tag and return the type of the variable with this tag
     * @param id
     * @return String with the type.
     */
    string search(const string &id);

    /**
     * \brief Get the Node wher a Tag was founded
     * @param tag
     * @return the LNode whith the equal tag, nullptr if not LNode
     */
    LNode *getNode(string);
    /**
     * \brief Get the json from the List
     * @return
     */
    string LJson();
};


#endif //PROYECTO_I_DII_C__LLIST_H
