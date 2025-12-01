#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* days_1_part_1(char* input) {
    char* ptr = strtok(input, "\n");
    int pos = 50;
    int c = 0;
    while (ptr != NULL) {
        char direction = ptr[0];
        int n = atoi(&ptr[1]);

        if (direction == 'L') {
            pos -= n;
        } else if (direction == 'R') {
            pos += n;
        }

        while (pos < 0) pos += 100;
        while (pos > 99) pos -= 100;

        if (pos == 0) {
            c++;
        }

        ptr = strtok(NULL, "\n");
    }

    char* result;
    asprintf(&result, "%d", c);
    return result;
}
