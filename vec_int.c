#include "vec_int.h"

#include <stdio.h>
#include <stdlib.h>

// ------------------------------------[Setup functions]-------------------------------------------

Vec_int init_vec() {
    Vec_int vec;

    vec.data = malloc(sizeof(int));
    if (vec.data == NULL) exit(1);

    vec.size = 0;

    return vec;
}

Vec_int copy(const Vec_int vec) {
    Vec_int vecCpy;

    vecCpy.data = malloc(sizeof(int) * vec.size);
    if (vecCpy.data == NULL) exit(1);

    vecCpy.size = vec.size;

    for (int i = 0; i < vec.size; i++) vecCpy.data[i] = vec.data[i];

    return vecCpy;
}

Vec_int concat(const Vec_int vec1, const Vec_int vec2) {
    Vec_int vec = copy(vec1);

    for (int i = 0; i < vec2.size; i++) push(&vec, vec2.data[i]);

    return vec;
}

Vec_int to_Vec_int(const int arr[], const unsigned int size) {
    Vec_int vec = init_vec();

    for (int i = 0; i < size; i++) push(&vec, arr[i]);

    return vec;
}

// ------------------------------[Functional Programming style functions]--------------------------

Vec_int push_fp(Vec_int* vec, const int val) {
    Vec_int new_vec = copy(*vec);

    new_vec.data = realloc(new_vec.data, new_vec.size + 1);
    if (new_vec.data == NULL) exit(1);

    new_vec.data[new_vec.size] = val;
    new_vec.size++;

    free(vec);
    return new_vec;
}

Vec_int pop_fp(Vec_int* vec) {
    if (vec->size > 0) {
        Vec_int new_vec = copy(*vec);

        new_vec.data = realloc(new_vec.data, new_vec.size - 1);
        if (new_vec.data == NULL) exit(1);

        new_vec.size--;

        free(vec);
        return new_vec;
    }
}

Vec_int insert_fp(Vec_int* vec, const int val, const unsigned int index) {
    if (index < 0 || index > vec->size - 1)
        printf("invalid index %d\n", index);
    else {
        Vec_int new_vec = copy(*vec);

        push(&new_vec, val);
        for (int i = new_vec.size - 1; i > index; i--) swap(&new_vec.data[i], &new_vec.data[i - 1]);

        free(vec);
        return new_vec;
    }
}

Vec_int del_fp(Vec_int* vec, const unsigned int index) {
    if (index < 0 || index > vec->size - 1)
        printf("invalid index %d", index);
    else {
        Vec_int new_vec = copy(*vec);

        for (int i = index; i < new_vec.size - 1; i++) swap(&new_vec.data[i], &new_vec.data[i + 1]);
        pop(&new_vec);

        free(vec);
        return new_vec;
    }
}

Vec_int fill_fp(Vec_int* vec, const int val, const unsigned int start, const unsigned int end) {
    if (start < 0 || end > vec->size)
        printf("invalid start %d or end %d\n", start, end);
    else {
        Vec_int new_vec = copy(*vec);

        for (int i = start; i < end; i++) new_vec.data[i] = val;

        free(vec);
        return new_vec;
    }
}

Vec_int map_fp(Vec_int* vec, int (*callback)()) {
    Vec_int new_vec = copy(*vec);

    for (int i = 0; i < new_vec.size; i++) new_vec.data[i] = callback(new_vec.data[i]);

    free(vec);
    return new_vec;
}

// ------------------------------[non Functional Programming style functions]----------------------

void push(Vec_int* vec, const int val) {
    vec->data = realloc(vec->data, vec->size + 1);
    if (vec->data == NULL) exit(1);

    vec->data[vec->size] = val;
    vec->size++;
}

void pop(Vec_int* vec) {
    if (vec->size > 0) {
        vec->data = realloc(vec->data, vec->size - 1);
        if (vec->data == NULL) exit(1);

        vec->size--;
    }
}

void insert(Vec_int* vec, const int val, const unsigned int index) {
    if (index < 0 || index > vec->size - 1)
        printf("invalid index %d\n", index);
    else {
        push(vec, val);
        for (int i = vec->size - 1; i > index; i--) swap(&vec->data[i], &vec->data[i - 1]);
    }
}

void del(Vec_int* vec, const unsigned int index) {
    if (index < 0 || index > vec->size - 1)
        printf("invalid index %d\n", index);
    else {
        for (int i = index; i < vec->size - 1; i++) swap(&vec->data[i], &vec->data[i + 1]);
        pop(vec);
    }
}

void fill(Vec_int* vec, const int val, const unsigned int start, const unsigned int end) {
    if (start < 0 || end > vec->size)
        printf("invalid start %d or end %d\n", start, end);
    else
        for (int i = start; i < end; i++) vec->data[i] = val;
}

void map(Vec_int* vec, int (*callback)()) {
    for (int i = 0; i < vec->size; i++) vec->data[i] = callback(vec->data[i]);
}

// ------------------------------------[Other functions]-------------------------------------------

int at(const Vec_int vec, const unsigned int index) {
    if (index < 0 || index > vec.size - 1)
        printf("invalid index %d\n", index);
    else
        return vec.data[index];
}

void print(const Vec_int vec) {
    putchar('\n');
    for (int i = 0; i < vec.size; i++) printf("%d\n", vec.data[i]);
}

bool equals(const Vec_int vec1, const Vec_int vec2) {
    if (vec1.size != vec2.size) return false;

    for (int i = 0; i < vec1.size; i++)
        if (vec1.data[i] != vec2.data[i]) return false;

    return true;
}

bool contains(const Vec_int vec, const int val) {
    for (int i = 0; i < vec.size; i++)
        if (vec.data[i] == val) return true;

    return false;
}

bool is_empty(const Vec_int vec) { return vec.size == 0; }

int indexOf(const Vec_int vec, const int val) {
    for (int i = 0; i < vec.size; i++)
        if (vec.data[i] == val) return i;

    printf("value %d not found\n", val);
    return -1;
}

static void swap(int* a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
