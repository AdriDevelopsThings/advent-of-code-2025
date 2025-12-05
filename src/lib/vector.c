#include <lib/vector.h>
#include <lib/safe_malloc.h>

struct vector vector_create() {
    struct vector vector;
    vector.capacity = VECTOR_DEFAULT_CAPACITY;
    vector.length = 0;
    vector.arr = (uint64_t*) safe_malloc(vector.capacity * sizeof(uint64_t));
    return vector;
}

void vector_destroy(struct vector* vector) {
    free(vector->arr);
}

void vector_capacity_increase(struct vector* vector) {
    vector->capacity *= 2;
    vector->arr = (uint64_t*) safe_realloc(vector->arr, vector->capacity * sizeof(uint64_t));
}

void vector_append(struct vector* vector, uint64_t item) {
    if (vector->capacity == vector->length) {
        vector_capacity_increase(vector);
    }

    vector->arr[vector->length++] = item;
}