#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdint.h>

#define VECTOR_DEFAULT_CAPACITY 32

struct vector {
    uint64_t* arr;
    size_t capacity;
    size_t length;
};

struct vector vector_create();
void vector_destroy(struct vector* vector);
void vector_append(struct vector* vector, uint64_t item);

#endif