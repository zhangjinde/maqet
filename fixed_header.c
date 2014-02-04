/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
The fixed header implementation.
*/

#include <stdio.h>
#include <assert.h>
#include "fixed_header.h"
#include "message_type.h"

const struct fixed_header* fixed_header_read(FILE* stream) {
    assert(stream);
    assert(!ferror(stream));
    assert(!ftell(stream));

    char buffer[2];
    size_t bytes_read = fread(buffer, sizeof buffer[0], sizeof(buffer), stream);
    // error, if bytes read is not equal 2.
    // error, if buffer[0] not in [1..15] range.
    enum message_type message_type = (enum message_type)(buffer[0] >> 4);   
    return NULL;
}

