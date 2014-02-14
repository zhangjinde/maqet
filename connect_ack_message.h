/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_CONNECT_ACK_MESSAGE_H
#define MAQET_CONNECT_ACK_MESSAGE_H

/*
The MQTT Connection Acknowledgment Message interface's structures and functions.
*/

#include <stdio.h>

/*
The MQTT Connection Acknowledgment Message structure.
The message sent by the server in response to an MQTT Connection request from a
client.
*/
struct connect_ack_message {
    struct message* message;
};

/*
Allocates a connection acknowledgment message.
On success, returns a pointer to a connection acknowledgment message, otherwise
NULL.
*/
struct connect_ack_message* connect_ack_message_new();

/*
Deallocates a connection acknowledgment message.
@message: a previously allocated connection acknowledgment message.
*/
void connect_ack_message_free(struct connect_ack_message* connect_ack_message);

/*
Reads a connection acknowledgment message from the supplied input stream.
@stream: a binary stream containing a connection acknowledgment message byte
sequence.
@message: a previously allocated connection acknowledgment message.
*/
void connect_ack_message_read(
    FILE* stream, 
    struct connect_ack_message* connect_ack_message);

/*
Writes a connection acknowledgment message into the supplied output stream.
@stream: a binary output stream.
@message:
*/
void connect_ack_message_write(
    FILE* stream, 
    struct connect_ack_message* connect_ack_message);

#endif

