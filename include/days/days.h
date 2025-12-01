#ifndef DAYS_H
#define DAYS_H

#define DAYS_LEN (sizeof(DAYS) / sizeof(struct day))

struct day {
    char* day;
    char* part;
    char* (*f)(char*);
};

extern const struct day DAYS[];

char* days_execute(char* day, char* part, char* input);

#endif
