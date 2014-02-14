/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
The MQTT Connection Acknowledgment message interface implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "connect_ack_message.h"

struct connect_ack_message* connect_ack_message_new() {
    return malloc(sizeof(struct connect_ack_message));
}

void connect_ack_message_free(struct connect_ack_message* connect_ack_message) {
    assert(connect_ack_message);

    free(connect_ack_message);
}

void connect_ack_message_read(
    FILE* stream, 
    struct connect_ack_message* connect_ack_message) {
    assert(stream);
    assert(!ferror(stream));
    assert(connect_ack_message);
}

