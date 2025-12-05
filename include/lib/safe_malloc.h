#ifndef SAFE_MALLOC_H
#define SAFE_MALLOC_H

#include <stdlib.h>
#include <stdio.h>

void* safe_malloc(size_t size);
void* safe_realloc(void* ptr, size_t size);

#endif
