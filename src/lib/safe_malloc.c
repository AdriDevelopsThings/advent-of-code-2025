#include <lib/safe_malloc.h>

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        perror("Error while allocating memory");
        exit(EXIT_FAILURE);
    }

    return ptr;
}

void* safe_realloc(void* o_ptr, size_t size) {
    void* ptr = realloc(o_ptr, size);
    if (ptr == NULL) {
        perror("Error while reallocating memory");
        exit(EXIT_FAILURE);
    }

    return ptr;
}
