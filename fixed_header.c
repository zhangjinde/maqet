/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
The fixed header implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fixed_header.h"
#include "message_type.h"

static const unsigned char fixed_header_size = 2;

const struct fixed_header* fixed_header_read(FILE* stream) {
    assert(stream);
    assert(!ferror(stream));
    assert(!ftell(stream));

    char buffer[fixed_header_size];
    size_t bytes_read = fread(buffer, sizeof buffer[0], sizeof(buffer), stream);
    // TODO: error, if bytes read is not equal 2.
    // TODO: error, if buffer[0] not in [1..15] range.
    struct fixed_header* fixed_header = malloc(sizeof fixed_header);
    fixed_header->message_type = (enum message_type)(buffer[0] >> 4);
    return fixed_header;
}

