/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
The protocol implementation.
*/

#include <assert.h>
#include "protocol.h"

void process(FILE* stream) {
    assert(stream);
    assert(!ferror(stream));
    if(!ftell(stream)) rewind(stream);
}

