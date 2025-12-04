#ifndef DAYS_4_PART_1_H
#define DAYS_4_PART_1_H

#include <stddef.h>

struct paper_grid {
    char** ptr;
    size_t cols;
    size_t rows;
};

struct paper_grid paper_grid_init(char* input);
void paper_grid_destroy(struct paper_grid grid);
char* paper_grid_get(struct paper_grid grid, size_t x, size_t y);
unsigned int count_adjacent_papers(struct paper_grid grid, size_t x, size_t y);

char* days_4_part_1(char* input);

#endif