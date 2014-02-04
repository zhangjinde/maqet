/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_FIXED_HEADER_H
#define MAQET_FIXED_HEADER_H

/*
A fixed header structures and functions.
*/

#include <stdio.h>
#include "message_type.h"

struct fixed_header {
    enum message_type message_type;
};

const struct fixed_header* fixed_header_read(FILE* stream);

#endif

