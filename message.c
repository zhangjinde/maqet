/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
An MQTT message interface implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "message.h"
#include "fixed_header.h"
#include "var_header.h"

struct message* message_new() {
    return malloc(sizeof(struct message));
}

void message_free(struct message* message) {
    assert(message);

    fixed_header_free(message->fixed_header);
    var_header_free(message->var_header);
    free(message);
}

void message_read(FILE* stream, struct message* message) {
    assert(stream);
    assert(!ferror(stream));
    assert(!ftell(stream));
    assert(message);
    assert(!message->fixed_header);
    assert(!message->var_header);
    
    message->fixed_header = fixed_header_new();
    fixed_header_read(stream, message->fixed_header);
    
    message->var_header = var_header_new();
    var_header_read(stream, message->var_header);
}

