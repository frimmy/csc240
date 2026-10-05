#ifndef NODETYPE_H
#define NODETYPE_H
#include <stddef.h>
// NodeType struct definition
template <class ItemType> struct NodeType {
    ItemType info;
    NodeType<ItemType>* next;
};
#endif
