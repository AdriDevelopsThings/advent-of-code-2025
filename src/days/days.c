#include <days/days.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <days/1/part_1.h>
#include <days/1/part_2.h>
#include <days/2/part_1.h>
#include <days/2/part_2.h>
#include <days/3/part_1.h>
#include <days/3/part_2.h>

const struct day DAYS[] = {
    { .day = "1", .part = "1", .f = &days_1_part_1 }, { .day = "1", .part = "2", .f = &days_1_part_2 },
    { .day = "2", .part = "1", .f = &days_2_part_1 }, { .day = "2", .part = "2", .f = &days_2_part_2 },
    { .day = "3", .part = "1", .f = &days_3_part_1 }, { .day = "3", .part = "2", .f = &days_3_part_2 }
};

const struct day* days_get(char* day, char* part) {
    for (size_t i = 0; i < DAYS_LEN; i++) {
        const struct day* s_day = &DAYS[i];
        if (strcmp(s_day->day, day) == 0 && strcmp(s_day->part, part) == 0) {
            return s_day;
        }
    }
    return NULL;
}

void days_print_available(FILE* target) {
    fprintf(target, "Available puzzles:\n");
    for (size_t i = 0; i < DAYS_LEN; i++) {
        const struct day* day = &DAYS[i];
        fprintf(target, "Day %s part %s\n", day->day, day->part);
    }
}

char* days_read_input_file(char* input_path) {
    FILE* file = fopen(input_path, "r");
    if (!file) {
        perror("Error while opening input file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buf = (char*) malloc(size + 1);
    size_t read = fread(buf, 1, size, file);
    fclose(file);

    buf[read] = '\0';

    return buf;
}

char* days_execute(char* day, char* part, char* input_path) {
    const struct day* s_day = days_get(day, part);
    if (s_day == NULL) {
        fprintf(stderr, "Error: Day %s part %s does not exist\n", day, part);
        days_print_available(stderr);
        exit(EXIT_FAILURE);
    }

    char* input = days_read_input_file(input_path);

    char* output = s_day->f(input);
    return output;
}
