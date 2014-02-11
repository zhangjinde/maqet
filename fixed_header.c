/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
An MQTT fixed header implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fixed_header.h"
#include "message_type.h"

static const unsigned char fixed_header_size = 0x02;

struct fixed_header* fixed_header_new() {
    return malloc(sizeof(struct fixed_header));
}

void fixed_header_free(struct fixed_header* fixed_header) {
    assert(fixed_header);

    free(fixed_header);
}

void fixed_header_read(FILE* stream, struct fixed_header* fixed_header) {
    assert(stream);
    assert(!ferror(stream));
    assert(!ftell(stream));
    assert(fixed_header);

    char buffer[fixed_header_size];
    fread(buffer, sizeof buffer[0], sizeof(buffer), stream);
    // TODO: error, if bytes read is not equal 2.
    // TODO: error, if buffer[0] not in [1..15] range.
    fixed_header->message_type = buffer[0] >> 4 & 0x0f;
    fixed_header->dup = buffer[0] >> 3 & 0x01;
    fixed_header->qos = buffer[0] >> 1 & 0x03;
    fixed_header->retain = buffer[0] & 0x01;
    // TODO: implement the variable length encoding scheme.
    fixed_header->remaining_size = buffer[1];
}

