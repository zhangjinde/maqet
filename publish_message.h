/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_PUBLISH_MESSAGE_H
#define MAQET_PUBLISH_MESSAGE_H

/*
The MQTT Publish Message interface's structures and functions.
*/

#include <stdio.h>

/*
The MQTT Publish Message structure.
*/
struct publish_message {
    /* Uniquely identifies the client to the server. */
    char* client_id;
    char* topic_name;
    char* message;
};

/*
Allocates an MQTT Publish Message.
On success, returns a pointer to a publish message, otherwise NULL.
*/
struct publish_message* publish_message_new();

/*
Deallocates a publish message.
@message: a previously allocated publish message.
*/
void publish_message_free(struct publish_message* publish_message);

/*
Reads an MQTT Publish Message from the supplied stream.
@stream: a binary stream containing an MQTT Publish message byte sequence.
@message: a previously allocated publish message.
*/
void publish_message_read(FILE* stream, struct publish_message* publish_message);

#endif

