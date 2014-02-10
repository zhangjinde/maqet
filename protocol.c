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
    message->fixed_header = malloc(sizeof(struct fixed_header));
    fixed_header_read(stream, message->fixed_header);
    message->var_header = malloc(sizeof(struct var_header));
    var_header_read(stream, message->var_header);
    // TODO: etc...
}

