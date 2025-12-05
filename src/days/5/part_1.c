#include <days/5/part_1.h>
#include <lib/list.h>
#include <string.h>

char* days_5_part_1(char* input) {
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

    unsigned int count = 0;
    while ((line = strsep(&input, "\n")) != NULL) {
        unsigned long i = strtoll(line, NULL, 10);

        list_elem_t* elem = ranges->first;
        while (elem != NULL) {
            struct range_elem* r_elem = (struct range_elem*) elem->elem;
            if (i >= r_elem->from && i <= r_elem->to) {
                count++;
                break;
            }
            elem = elem->next;
        }
    }

    list_destroy(ranges);
    char* result;
    asprintf(&result, "%d", count);
    return result;
}