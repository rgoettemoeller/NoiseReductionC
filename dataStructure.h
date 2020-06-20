#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

typedef struct values{
    unsigned long long t[10];
    short p;
} values;

extern void fillTimeArray(values *ValuesElement, unsigned long long timeValue, short p);

#endif