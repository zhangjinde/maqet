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
#include "publish_message.h"
#include "string.h"

struct publish_message* publish_message_new() {
    return malloc(sizeof(struct publish_message));
}

void publish_message_free(struct publish_message* publish_message) {
    assert(publish_message);

}

void publish_message_read(FILE* stream, struct publish_message* publish_message) {
    assert(stream);
    assert(!ferror(stream));
    assert(publish_message);

}

