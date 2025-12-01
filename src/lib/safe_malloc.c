#include <lib/safe_malloc.h>

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        perror("Error while allocating memory");
        exit(EXIT_FAILURE);
    }

    return ptr;
}
