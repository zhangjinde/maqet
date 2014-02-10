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
#include "string.h"

static const char* protocol_name = "MQIsdp";
static const unsigned char protocol_version = 0x03;

void var_header_read(FILE* stream, struct var_header* var_header) {
    assert(stream);
    assert(!ferror(stream));
    assert(var_header);

    // TODO: complete the implementation.
    string_read(stream, var_header->protocol_name);
}

