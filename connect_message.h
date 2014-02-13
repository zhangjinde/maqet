/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_CONNECT_MESSAGE_H
#define MAQET_CONNECT_MESSAGE_H

/*
The MQTT Connect Message interface's structures and functions.
*/

#include <stdio.h>

/*
The MQTT Connect Message structure.
*/
struct connect_message {
};

/*
Allocates an MQTT Connect Message.
On success, returns a pointer to a connect message, otherwise NULL.
*/
struct connect_message* connect_message_new();

/*
Deallocates a connect message.
@message: a previously allocated connect message.
*/
void connect_message_free(struct connect_message* connect_message);

/*
Reads an MQTT Connect Message from the supplied stream.
@stream: a binary stream containing an MQTT Connect message byte sequence.
@message: a previously allocated connect message.
*/
void connect_message_read(FILE* stream, struct connect_message* connect_message);

#endif

