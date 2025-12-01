#ifndef ARGS_H
#define ARGS_H

struct args {
    char* day;
    char* part;
    char* input;
};

struct args args_parse(int argc, char* argv[]);

#endif
