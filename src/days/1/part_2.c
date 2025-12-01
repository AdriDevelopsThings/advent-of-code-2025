#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* days_1_part_2(char* input) {
    char* ptr = strtok(input, "\n");
    int pos = 50;
    int c = 0;
    while (ptr != NULL) {
        char direction = ptr[0];
        int n = atoi(&ptr[1]);
        int i = n / 100;
        n = n % 100;

        if (direction == 'L') {
            if (pos != 0 && n >= pos)
                i++;
            pos -= n;
        } else if (direction == 'R') {
            if (n >= (100 - pos))
                i++;
            pos += n;
        }
        c += i;

        while (pos < 0) pos += 100;
        while (pos > 99) pos -= 100;

        ptr = strtok(NULL, "\n");
    }

    char* result;
    asprintf(&result, "%d", c);
    return result;
}
