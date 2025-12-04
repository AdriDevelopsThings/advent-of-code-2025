#include <days/4/part_1.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct paper_grid paper_grid_init(char* input) {
    size_t capacity = 8;
    size_t length = 0;

    char** arr = (char**) malloc(capacity * sizeof(char*));

    char* ptr = strtok(input, "\n");
    size_t cols = strlen(ptr);
    while (ptr != NULL) {
        char* ptr_copy = (char*) malloc(sizeof(char) * cols);
        memcpy(ptr_copy, ptr, cols);

        if (length == capacity) {
            capacity *= 2;
            arr = realloc(arr, capacity * sizeof(char*));
        }

        arr[length++] = ptr_copy;

        ptr = strtok(NULL, "\n");
    }

    struct paper_grid grid = { .ptr = arr, .rows = length, .cols = cols };
    return grid;
}

void paper_grid_destroy(struct paper_grid grid) {
    for (size_t x = 0; x < grid.rows; x++) {
        free(grid.ptr[x]);
    }
    free(grid.ptr);
}

char* paper_grid_get(struct paper_grid grid, size_t x, size_t y) {
    if (x < 0 || x >= grid.rows || y < 0 || y >= grid.cols) {
        return NULL;
    }
    return &grid.ptr[x][y];
}

unsigned int count_adjacent_papers(struct paper_grid grid, size_t x, size_t y) {
    unsigned int count = 0;

    for (int x_d = -1; x_d <= 1; x_d++) {
        for (int y_d = -1; y_d <= 1; y_d++) {
            if (x_d == 0 && y_d == 0)
                continue;

            char* ptr = paper_grid_get(grid, x + x_d, y + y_d);
            if (ptr != NULL && *ptr == '@')
                count++;
        }
    }

    return count;
}

char* days_4_part_1(char* input) {
    struct paper_grid grid = paper_grid_init(input);
    unsigned int count = 0;
    for (size_t x = 0; x < grid.rows; x++) {
        for (size_t y = 0; y < grid.cols; y++) {
            if (grid.ptr[x][y] != '@')
                continue;
            if (count_adjacent_papers(grid, x, y) < 4) {
                count++;
            }
        }
    }

    paper_grid_destroy(grid);
    char* result;
    asprintf(&result, "%d", count);
    return result;
}