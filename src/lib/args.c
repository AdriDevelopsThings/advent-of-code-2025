#include <lib/args.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void usage(char* exec) {
    fprintf(stderr,
            "Usage: %s [OPTIONS] <DAY> <PART>\n\nOptions:\n\t-i: Specify the input file (By default input/{day}.txt)\n",
            exec);
    exit(EXIT_FAILURE);
}

struct args args_parse(int argc, char* argv[]) {
    char* exec = argv[0];
    struct args args;
    args.input = NULL;

    int c;

    while ((c = getopt(argc, argv, "i:")) != -1) {
        switch (c) {
            case 'i':
                args.input = optarg;
                break;
            case '?':
            default:
                usage(exec);
        }
    }

    argc -= optind;
    argv += optind;

    if (argc != 2) {
        usage(exec);
    }

    args.day = argv[0];
    args.part = argv[1];

    return args;
}
