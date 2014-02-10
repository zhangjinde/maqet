/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
The variable header implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "var_header.h"
#include "string.h"

static const char* protocol_name = "MQIsdp";
static const unsigned char protocol_version = 0x03;

void var_header_free(struct var_header* var_header) {
    assert(var_header);

    free(var_header->protocol_name);
    free(var_header);
}

void var_header_read(FILE* stream, struct var_header* var_header) {
    assert(stream);
    assert(!ferror(stream));
    assert(var_header);

    // TODO: complete the implementation.
    var_header->protocol_name = string_read(stream);
}

