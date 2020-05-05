#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList init_list() {
    LinkedList l;

    l.head = malloc(sizeof(Node));
    if (l.head == NULL) exit(1);
    l.tail = malloc(sizeof(Node));
    if (l.tail == NULL) exit(1);
    l.size = 0;

    return l;
}

void add(LinkedList* l, const int data) {
    if (l->size == 0)
        l->head = l->tail = create_node(data);
    else {
        l->tail->next = create_node(data);
        l->tail = l->tail->next;
    }
    l->size++;
}

void supr(LinkedList* l, const int data) {
    if (data == l->head->data)
        l->head = l->head->next;
    else {
        Node* current = l->head;
        while (current->next->data != data) {
            if (current->next == NULL) return;
            current = current->next;
        }
        if (current->next == l->tail) l->tail = current;
        current->next = current->next->next;
    }
    l->size--;
}

void display(const LinkedList l) {
    Node* current = l.head;
    while (current->next != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}
