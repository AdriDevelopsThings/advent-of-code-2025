#include <string.h>
#include <stdio.h>

unsigned int char_to_uint(char c) {
    return c - 48;
}

char* find_largest_num_n(char* digits, size_t n) {
    char* max_s;
    unsigned int max = 0;
    for (size_t i = 0; i < n; i++) {
        unsigned int num = char_to_uint(digits[i]);
        if (num > max) {
            max_s = &digits[i];
            max = num;
        }
    }
    return max_s;
}

unsigned long find_n_batteries(char* batteries, size_t n) {
    unsigned long sum = 0;
    char* ptr = batteries;

    for (size_t i = 0; i < n; i++) {
        char* battery = find_largest_num_n(ptr, strlen(ptr) - n + i + 1);
        ptr = &battery[1];
        sum *= 10;
        sum += char_to_uint(*battery);
    }

    return sum;
}

char* days_3_part_1(char* input) {
    unsigned long sum = 0;
    char* ptr;

    ptr = strtok(input, "\n");

    while (ptr != NULL) {
        sum += find_n_batteries(ptr, 2);
        ptr = strtok(NULL, "\n");
    }

    char* result;
    asprintf(&result, "%lu", sum);
    return result;
}