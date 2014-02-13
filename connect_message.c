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
#include "string.h"

struct connect_message* connect_message_new() {
    return malloc(sizeof(struct connect_message));
}

void connect_message_free(struct connect_message* connect_message) {
    assert(connect_message);

    free(connect_message->client_id);
    free(connect_message->topic_name);
    free(connect_message->message);
    free(connect_message->username);
    free(connect_message->password);
    free(connect_message);
}

void connect_message_read(FILE* stream, struct connect_message* connect_message) {
    assert(stream);
    assert(!ferror(stream));
    assert(connect_message);

    connect_message->client_id = string_read(stream);
    connect_message->topic_name = string_read(stream);
    connect_message->message = string_read(stream);
    connect_message->username = string_read(stream);
    connect_message->password = string_read(stream);
}

