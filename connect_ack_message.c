/*
* Project maqet.
* Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>.
*/

/* The MQTT Connection Acknowledgment message interface implementation. */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "connect_ack_message.h"
#include "message.h"
#include "fixed_header.h"
#include "var_header.h"

struct connect_ack_message* connect_ack_message_new() {
    return malloc(sizeof(struct connect_ack_message));
}

void connect_ack_message_free(struct connect_ack_message* connect_ack_message) {
    assert(connect_ack_message);

    message_free(connect_ack_message->message);
    free(connect_ack_message);
}

void connect_ack_message_read(
    FILE* stream, 
    struct connect_ack_message* connect_ack_message) {
    assert(stream);
    assert(!ferror(stream));
    assert(connect_ack_message);
}

void connect_ack_message_write(
    FILE* stream, 
    struct connect_ack_message* connect_ack_message) {
    assert(stream);
    assert(!ferror(stream));
    assert(connect_ack_message);

    fixed_header_write(stream, connect_ack_message->message->fixed_header);
    var_header_write(stream, connect_ack_message->message->var_header);
}

