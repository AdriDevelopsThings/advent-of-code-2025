#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <lib/args.h>
#include <days/days.h>

int main(int argc, char* argv[]) {
    bool args_input_alloc = false;
    struct args args = args_parse(argc, argv);
    if (args.input == NULL) {
        asprintf(&args.input, "input/%s.txt", args.day);
        args_input_alloc = true;
    }

    char* o = days_execute(args.day, args.part, args.input);

    printf("%s\n", o);
    free(o);

    if (args_input_alloc) {
        free(args.input);
    }
}
