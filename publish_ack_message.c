/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
The MQTT Publish Acknowledgment message interface implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "publish_ack_message.h"
#include "message.h"
#include "fixed_header.h"
#include "var_header.h"

struct publish_ack_message* publish_ack_message_new() {
    return malloc(sizeof(struct publish_ack_message));
}

void publish_ack_message_free(struct publish_ack_message* publish_ack_message) {
    assert(publish_ack_message);

    message_free(publish_ack_message->message);
    free(publish_ack_message);
}

void publish_ack_message_read(
    FILE* stream, 
    struct publish_ack_message* publish_ack_message) {
    assert(stream);
    assert(!ferror(stream));
    assert(publish_ack_message);
}

void publish_ack_message_write(
    FILE* stream, 
    struct publish_ack_message* publish_ack_message) {
    assert(stream);
    assert(!ferror(stream));
    assert(publish_ack_message);

    fixed_header_write(stream, publish_ack_message->message->fixed_header);
    var_header_write(stream, publish_ack_message->message->var_header);
}

