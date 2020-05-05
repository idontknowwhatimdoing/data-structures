#ifndef NODE
#define NODE

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(const int data);

#endif
