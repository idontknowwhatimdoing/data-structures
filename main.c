#include <stdio.h>

#include "linkedlist.h"
#include "vec_int.h"

int main(int argc, char const* argv[]) {
    Vec_int vec = init_vec();
    push(&vec, 42);
    push(&vec, 69);
    push(&vec, 911);
    push(&vec, 177013);
    del(&vec, indexOf(vec, 911));
    print(vec);

    putchar('\n');

    LinkedList list = init_list();
    add(&list, -12);
    add(&list, 100);
    add(&list, -7);
    add(&list, 20);
    supr(&list, 20);
    supr(&list, -12);
    display(list);
    printf("head : %d\ntail : %d\n", list.head->data, list.tail->data);
    return 0;
}
