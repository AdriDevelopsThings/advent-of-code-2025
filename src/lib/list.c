#include <lib/list.h>

list_t list_create() {
    list_t list = (list_t) safe_malloc(sizeof(struct list));

    list->first = NULL;
    list->last = NULL;
    list->length = 0;

    return list;
}

void list_destroy(list_t list) {
    struct list_elem* elem = list->first;
    while (elem != NULL) {
        struct list_elem* next = elem->next;
        if (elem->owned)
            free(elem->elem);
        free(elem);
        elem = next;
    }
}

void list_append(list_t list, void* elem, bool owned) {
    struct list_elem* l_elem = (struct list_elem*) safe_malloc(sizeof(struct list_elem));
    l_elem->elem = elem;
    l_elem->owned = owned;
    l_elem->next = NULL;

    list->length++;

    if (list->last) {
        l_elem->prev = list->last;
        list->last->next = l_elem;
        list->last = l_elem;
    } else {
        list->first = l_elem;
        list->last = l_elem;
        l_elem->prev = NULL;
        l_elem->next = NULL;
    }
}

void list_remove(list_elem_t* elem) {
    if (elem->owned)
        free(elem->elem);
    elem->elem = NULL;
}