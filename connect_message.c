/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
The MQTT Connect Message interface implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "connect_message.h"

struct connect_message* connect_message_new() {
    return malloc(sizeof(struct connect_message));
}

void connect_message_free(struct connect_message* connect_message) {
    assert(connect_message);

    free(connect_message);
}

void connect_message_read(FILE* stream, struct connect_message* connect_message) {
    assert(stream);
    assert(!ferror(stream));
    assert(connect_message);

    // TODO: etc...
}

