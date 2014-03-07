/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_PUBLISH_ACK_MESSAGE_H
#define MAQET_PUBLISH_ACK_MESSAGE_H

/*
The MQTT Publish Acknowledgment Message interface's structures and functions.
*/

#include <stdio.h>

/*
The MQTT Publish Acknowledgment Message structure.
The message sent by the server in response to an MQTT Publish request from a
client.
*/
struct publish_ack_message {
    struct message* message;
};

/*
Allocates a publish acknowledgment message.
On success, returns a pointer to a publish acknowledgment message, otherwise
NULL.
*/
struct publish_ack_message* publish_ack_message_new();

/*
Deallocates a publish acknowledgment message.
@message: a previously allocated publish acknowledgment message.
*/
void publish_ack_message_free(struct publish_ack_message* publish_ack_message);

/*
Reads a publish acknowledgment message from the supplied input stream.
@stream: a binary stream containing a publish acknowledgment message byte
sequence.
@message: a previously allocated publish acknowledgment message.
*/
void publish_ack_message_read(
    FILE* stream, 
    struct publish_ack_message* publish_ack_message);

/*
Writes a publish acknowledgment message into the supplied output stream.
@stream: a binary output stream.
@message:
*/
void publish_ack_message_write(
    FILE* stream, 
    struct publish_ack_message* publish_ack_message);

#endif

