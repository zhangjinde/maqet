/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_FIXED_HEADER_H
#define MAQET_FIXED_HEADER_H

/*
An MQTT fixed header structures and functions.
*/

#include <stdio.h>
#include <stdbool.h>
#include "message_type.h"
#include "qos.h"

/*
An MQTT fixed header structure.
*/
struct fixed_header {
    /* The MQTT message type enumeration. */
    enum message_type message_type;

    /*
    This flag is set when the client or server attempts to re-deliver a
    PUBLISH, PUBREL, SUBSCRIBE or UNSUBSCRIBE message. This applies to messages
    where the value of QoS is greater than zero (0), and an acknowledgment is
    required. When the DUP bit is set, the variable header includes a Message
    ID.
    */
    bool dup;

    /*
    This flag indicates the level of assurance for delivery of a PUBLISH
    message.
    */
    enum qos qos;

    /*
    This flag is only used on PUBLISH messages. When a client sends a PUBLISH
    to a server, if the Retain flag is set (1), the server should hold on to
    the message after it has been delivered to the current subscribers.
    */
    bool retain;

    /*
    The number of bytes remaining within the current message, including data in
    the variable header and the payload.
    */
    unsigned char remaining_size;
};

/*
Allocates a fixed header.
On success, returns a pointer to a fixed header, otherwise NULL.
*/
struct fixed_header* fixed_header_new();

/*
Deallocates a previously allocated fixed header.
@fixed_header: a previously allocated fixed header.
*/
void fixed_header_free(struct fixed_header* fixed_header);

/*
Reads a fixed header from the supplied stream.
@stream:
@fixed_header:
*/
void fixed_header_read(FILE* stream, struct fixed_header* fixed_header);

/*
Writes a fixed header into the supplied output stream.
@stream: a binary output stream.
@fixed_header:
*/
void fixed_header_write(FILE* stream, struct fixed_header* fixed_header);

#endif

