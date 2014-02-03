/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_FIXED_HEADER_H
#define MAQET_FIXED_HEADER_H

/*
A fixed header structures and functions.
*/

#include <stdio.h>

struct fixed_header {
    unsigned char type: 4;
    unsigned char dup: 1;
    unsigned char qos: 2;
    unsigned char retain: 1;
    unsigned char size;
};

struct fixed_header* fixed_header_read(FILE* stream);

#endif

