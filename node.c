#include "node.h"

#include <stdlib.h>

Node* create_node(const int data) {
    Node* n = malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}
