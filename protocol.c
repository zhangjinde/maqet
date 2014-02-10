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
#include "var_header.h"

void protocol_message_read(FILE* stream, struct message* message) {
    assert(stream);
    assert(!ferror(stream));

    if(ftell(stream)) rewind(stream);
    struct fixed_header* fixed_header = malloc(sizeof(fixed_header));
    fixed_header_read(stream, fixed_header);
    struct var_header* var_header = malloc(sizeof(var_header));
    var_header_read(stream, var_header);
    // TODO: etc...
    free(fixed_header);
    free(var_header);
}

