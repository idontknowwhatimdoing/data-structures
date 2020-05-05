#ifndef LINKEDLIST
#define LINKEDLIST

#include "node.h"

typedef struct LinkedList {
    Node* head;
    Node* tail;
    unsigned int size;
} LinkedList;

LinkedList init_list();

void add(LinkedList* l, const int data);

void supr(LinkedList* l, const int data);

void display(const LinkedList l);

#endif
