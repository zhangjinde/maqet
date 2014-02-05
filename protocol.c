/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
The protocol implementation.
*/

#include <stdlib.h>
#include <assert.h>
#include "protocol.h"
#include "fixed_header.h"

const struct message* protocol_message_read(FILE* stream) {
    assert(stream);
    assert(!ferror(stream));

    if(ftell(stream)) rewind(stream);
    struct fixed_header* fixed_header = malloc(sizeof(fixed_header));
    fixed_header_read(stream, fixed_header);
    // TODO: etc...
    free(fixed_header);
    return NULL;
}

