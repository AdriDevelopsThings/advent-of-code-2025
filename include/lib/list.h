#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <lib/safe_malloc.h>

typedef struct list_elem {
    struct list_elem* prev;
    struct list_elem* next;
    void* elem;
    bool owned;
} list_elem_t;

typedef struct list {
    struct list_elem* first;
    struct list_elem* last;
    size_t length;
}* list_t;

list_t list_create();
void list_destroy(list_t list);
void list_append(list_t list, void* elem, bool owned);
void list_remove(list_elem_t* elem);

#endif
