#include <days/4/part_1.h>
#include <stdio.h>

char* days_4_part_2(char* input) {
    struct paper_grid grid = paper_grid_init(input);
    unsigned int count = 0;
    unsigned int old_count = 1;
    while (count != old_count) {
        old_count = count;
        for (size_t x = 0; x < grid.rows; x++) {
            for (size_t y = 0; y < grid.cols; y++) {
                if (grid.ptr[x][y] != '@')
                    continue;
                if (count_adjacent_papers(grid, x, y) < 4) {
                    count++;
                    grid.ptr[x][y] = 'x';
                }
            }
        }
    }

    paper_grid_destroy(grid);
    char* result;
    asprintf(&result, "%d", count);
    return result;
}