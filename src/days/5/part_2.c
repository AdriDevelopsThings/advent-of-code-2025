#include <days/5/part_1.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <lib/list.h>

bool range_is_overlapping(struct range_elem* a, struct range_elem* b) {
    return a->from <= b->to && a->to >= b->from;
}

void range_merge(struct range_elem* dst, struct range_elem* src) {
    if (src->from < dst->from)
        dst->from = src->from;
    if (src->to > dst->to)
        dst->to = src->to;
}

char* days_5_part_2(char* input) {
    char* line;

    list_t ranges = list_create();

    while ((line = strsep(&input, "\n")) != NULL && *line != '\0') {
        struct range_elem* elem = (struct range_elem*) safe_malloc(sizeof(struct range_elem));
        char* r_ptr;
        r_ptr = strtok(line, "-");
        elem->from = strtoll(r_ptr, NULL, 10);
        r_ptr = strtok(NULL, "-");
        elem->to = strtoll(r_ptr, NULL, 10);

        list_append(ranges, elem, true);
    }

    bool did_merge = true;
    while (did_merge) {
        did_merge = false;
        list_elem_t* o_elem = ranges->first;
        while (o_elem != NULL) {
            if (o_elem->elem == NULL)
                goto mo_loop_end;
            struct range_elem* or_elem = (struct range_elem*) o_elem->elem;

            list_elem_t* i_elem = ranges->first;
            while (i_elem != NULL) {
                if (i_elem == o_elem || i_elem->elem == NULL)
                    goto mi_loop_end;

                struct range_elem* ir_elem = (struct range_elem*) i_elem->elem;
                if (range_is_overlapping(or_elem, ir_elem)) {
                    range_merge(or_elem, ir_elem);
                    list_remove(i_elem);
                    did_merge = true;
                }

mi_loop_end:
                i_elem = i_elem->next;
            }

mo_loop_end:
            o_elem = o_elem->next;
        }
    }

    unsigned long count = 0;
    list_elem_t* elem = ranges->first;
    while (elem != NULL) {
        if (elem->elem == NULL)
            goto c_loop_end;

        struct range_elem* r = (struct range_elem*) elem->elem;
        count += r->to - r->from + 1;

c_loop_end:
        elem = elem->next;
    }

    list_destroy(ranges);

    char* result;
    asprintf(&result, "%lu", count);
    return result;
}