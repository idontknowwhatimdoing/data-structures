#ifndef VECTORINT
#define VECTORINT

#include <stdbool.h>

typedef struct Vec_int {
    int* data;
    unsigned int size;
} Vec_int;

// ------------------------------------[Setup functions]-------------------------------------------

Vec_int init_vec();

Vec_int copy(const Vec_int vec);

Vec_int concat(const Vec_int vec1, const Vec_int vec2);

Vec_int to_Vec_int(const int arr[], const unsigned int size);

// ------------------------------[Functional Programming style functions]--------------------------

Vec_int push_fp(Vec_int* vec, const int val);

Vec_int pop_fp(Vec_int* vec);

Vec_int insert_fp(Vec_int* vec, const int val, const unsigned int index);

Vec_int del_fp(Vec_int* vec, const unsigned int index);

Vec_int fill_fp(Vec_int* vec, const int val, const unsigned int start, const unsigned int end);

Vec_int map_fp(Vec_int* vec, int (*callback)());

// ------------------------------[non Functional Programming style functions]----------------------

void push(Vec_int* vec, const int val);

void pop(Vec_int* vec);

void insert(Vec_int* vec, const int val, const unsigned int index);

void del(Vec_int* vec, const unsigned int index);

void fill(Vec_int* vec, const int val, const unsigned int start, const unsigned int end);

void map(Vec_int* vec, int (*callback)());

// ------------------------------------[Other functions]-------------------------------------------

int at(const Vec_int vec, const unsigned int index);

void print(const Vec_int vec);

bool equals(const Vec_int vec1, const Vec_int vec2);

bool contains(const Vec_int vec, const int val);

bool is_empty(const Vec_int vec);

int indexOf(const Vec_int vec, const int val);

static void swap(int* a, int* b);

#endif
