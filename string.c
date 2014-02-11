/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
The MQTT string decoding and encoding routines's implementation.
*/

#include <stdlib.h>
#include <assert.h>
#include "string.h"

char* string_read(FILE* stream) {
    assert(stream);
    assert(!ferror(stream));

    unsigned char length_buffer[2];
    // TODO: take care of the interrupts.
    size_t bytes_read = fread(length_buffer, sizeof length_buffer[0], sizeof(length_buffer), stream);
    unsigned short length = length_buffer[0] << 8 | length_buffer[1];
    char* string = malloc(sizeof(char) * length);
    // TODO: take care of the interrupts.
    bytes_read = fread(string, sizeof string[0], sizeof(string), stream);
    return string;
}

