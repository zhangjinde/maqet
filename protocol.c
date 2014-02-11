/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
An MQTT protocol implementation.
*/

#include <stdlib.h>
#include <assert.h>
#include "protocol.h"
#include "fixed_header.h"
#include "var_header.h"

void protocol_message_read(FILE* stream, struct message* message) {
    assert(stream);
    assert(!ferror(stream));
    assert(message);

    if(ftell(stream)) rewind(stream);
    message_read(stream, message);
    // TODO: etc...
}

