/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
The variable header implementation.
*/

#include <stdio.h>
#include <assert.h>
#include "var_header.h"

static const char* protocol_name = u8"MQIsdp";
static const unsigned char protocol_version = 0x03;

void var_header_read(FILE* stream, struct var_header* var_header) {
    assert(stream);
    assert(!ferror(stream));
    assert(!ftell(stream));
    assert(var_header);

    char buffer[fixed_header_size];
    size_t bytes_read = fread(buffer, sizeof buffer[0], sizeof(buffer), stream);
    // TODO: complete the implementation.
    var_header->protocol_name = buffer[0] >> 4 & 0xf;
}

