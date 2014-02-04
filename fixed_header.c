/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
The fixed header implementation.
*/

#include <stdio.h>
#include <assert.h>
#include "fixed_header.h"

struct fixed_header* fixed_header_read(FILE* stream) {
    assert(stream);
    assert(!ferror(stream));
    assert(!ftell(stream));

    return NULL;
}

