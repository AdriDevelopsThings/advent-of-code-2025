#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <lib/safe_malloc.h>

bool is_invalid_id_2(unsigned long id) {
    char* id_s;
    size_t id_len;
    bool result = false;

    asprintf(&id_s, "%lu", id);
    id_len = strlen(id_s);

    for (size_t times = 2; times <= id_len; times++) {
        if (id_len % times != 0) {
            continue;
        }

        size_t step = id_len / times;

        bool match = true;
        for (size_t i = 1; i < times; i++) {
            if (strncmp(id_s, &id_s[step * i], step) != 0) {
                match = false;
                break;
            }
        }

        if (match) {
            result = true;
            break;
        }
    }

    free(id_s);
    return result;
}

char* days_2_part_2(char* input) {
    char *o_saveptr, *o_ptr, *i_saveptr, *i_ptr;
    unsigned long sum = 0;
    o_ptr = strtok_r(input, ",", &o_saveptr);

    while (o_ptr != NULL) {
        unsigned long from, to;

        i_ptr = strtok_r(o_ptr, "-", &i_saveptr);
        from = strtoul(i_ptr, NULL, 10);
        i_ptr = strtok_r(NULL, "-", &i_saveptr);
        to = strtoul(i_ptr, NULL, 10);

        for (unsigned long i = from; i <= to; i++) {
            if (is_invalid_id_2(i))
                sum += i;
        }

        i_saveptr = NULL;
        o_ptr = strtok_r(NULL, ",", &o_saveptr);
    }

    char* output;
    asprintf(&output, "%lu", sum);
    return output;
}