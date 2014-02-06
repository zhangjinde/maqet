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
#include <stdbool.h>
#include "message_type.h"
#include "qos.h"

struct fixed_header {
    enum message_type message_type;
    bool dup;
    enum qos qos;
    bool retain;

    /*
    Represents the number of bytes remaining within the current message, including data in
    the variable header and the payload.
    */
    unsigned char remaining_size;
};

void fixed_header_read(FILE* stream, struct fixed_header* fixed_header);

#endif

