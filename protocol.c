/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
The protocol implementation.
*/

#include <assert.h>
#include "protocol.h"
#include "fixed_header.h"

void protocol_read(FILE* stream) {
    assert(stream);
    assert(!ferror(stream));

    if(ftell(stream)) rewind(stream);
    const struct fixed_header* fixed_header = fixed_header_read(stream);
}

