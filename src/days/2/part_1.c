#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <lib/safe_malloc.h>

bool is_invalid_id(unsigned long id) {
    char* id_s;
    size_t id_len;
    bool result;

    asprintf(&id_s, "%lu", id);

    id_len = strlen(id_s);
    if (id_len % 2 != 0) {
        result = false;
        goto end;
    }

    result = strncmp(id_s, &id_s[id_len / 2], id_len / 2) == 0;

end:
    free(id_s);
    return result;
}

char* days_2_part_1(char* input) {
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
            if (is_invalid_id(i))
                sum += i;
        }

        i_saveptr = NULL;
        o_ptr = strtok_r(NULL, ",", &o_saveptr);
    }

    char* output;
    asprintf(&output, "%lu", sum);
    return output;
}