/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_FIXED_HEADER_H
#define MAQET_FIXED_HEADER_H

/*
An MQTT fixed header structures and functions.
*/

#include <stdio.h>
#include <stdbool.h>
#include "message_type.h"
#include "qos.h"

/*
An MQTT fixed header structure.
*/
struct fixed_header {
    enum message_type message_type;
    bool dup;
    enum qos qos;
    bool retain;

    /*
    The number of bytes remaining within the current message, including data in
    the variable header and the payload.
    */
    unsigned char remaining_size;
};

/*
Allocates a fixed header.
On success, returns a pointer to a fixed header, otherwise NULL.
*/
struct fixed_header* fixed_header_new();

/*
Deallocates a previously allocated fixed header.
@fixed_header: a previously allocated fixed header.
*/
void fixed_header_free(struct fixed_header* fixed_header);

/*
Reads a fixed header from a stream.
@stream:
@fixed_header:
*/
void fixed_header_read(FILE* stream, struct fixed_header* fixed_header);

#endif

