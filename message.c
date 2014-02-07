/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
The message implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "message.h"
#include "fixed_header.h"
#include "var_header.h"

/*
Allocates a new message.
On success, returns a new message, otherwise NULL.
*/
struct message* message_new() {
    return malloc(sizeof(struct message));
}

/*
Deallocates a message.
@message: a previously allocated message.
*/
void message_free(struct message* message) {
    assert(message);

    if(message->fixed_header) free(fixed_header);
    if(message->var_header) free(var_header);
    if(message->payload_header) free(payload_header);
    free(message);
}

/*
Parses a stream and reads a message from a stream.
@stream: a binary stream containing message byte sequence.
@message: a previously allocated message.
*/
void message_read(FILE* stream, struct message* message) {
    assert(stream);
    assert(!ferror(stream));
    assert(!ftell(stream));
    assert(message);
    assert(!message->fixed_header);
    assert(!message->var_header);
    assert(!message->payload);
    
    message->fixed_header = malloc(sizeof(struct fixed_header));
    fixed_header_read(message->fixed_header);
    
    message->var_header = malloc(sizeof(struct var_header));
    var_header_read(message->var_header);

    // TODO: need a paylaod?
    // message->payload = malloc(sizeof(struct payload));
    // payload_read(message->payload);
}

