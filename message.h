/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_MESSAGE_H
#define MAQET_MESSAGE_H

/*
An MQTT message interface's structures and functions.
*/

#include <stdio.h>

/*
An MQTT message structure.

The message header for each MQTT command message contains a fixed header. Some
messages also require a variable header and a payload.
*/
struct message {
    /*
    A fixed header.
    
    The message header for each MQTT command message contains
    a fixed header.
    */
    struct fixed_header* fixed_header;

    /*
    A variable header.
    
    Some types of MQTT command messages also contain a variable header
    component. It resides between the fixed header and the payload.  
    */
    struct var_header* var_header;

    /*
    A payload.
    
    The following types of MQTT command message have a payload:
    
    CONNECT: The payload contains one or more UTF-8 encoded strings. They specify a
    unqiue identifier for the client, a Will topic and message and the User Name
    and Password to use. All but the first are optional and their presence is
    determined based on flags in the variable header.
    
    SUBSCRIBE: The payload contains a list of topic names to which the client can
    subscribe, and the QoS level. These strings are UTF-encoded.
    
    SUBACK: The payload contains a list of granted QoS levels. These are the QoS
    levels at which the administrators for the server have permitted the client to
    subscribe to a particular Topic Name. Granted QoS levels are listed in the
    same order as the topic names in the corresponding SUBSCRIBE message.

    */
    struct payload* payload;
};

/*
Allocates an MQTT message.
On success, returns a pointer to a message, otherwise NULL.
*/
struct message* message_new();

/*
Deallocates a message.
@message: a previously allocated message.
*/
void message_free(struct message* message);

/*
Reads an MQTT message from the supplied stream.
@stream: a binary stream containing an MQTT message byte sequence.
@message: a previously allocated message.
*/
void message_read(FILE* stream, struct message* message);

#endif

