#include <days/3/part_1.h>
#include <stdio.h>
#include <string.h>

char* days_3_part_2(char* input) {
    unsigned long sum = 0;
    char* ptr;

    ptr = strtok(input, "\n");

    while (ptr != NULL) {
        sum += find_n_batteries(ptr, 12);
        ptr = strtok(NULL, "\n");
    }

    char* result;
    asprintf(&result, "%lu", sum);
    return result;
}