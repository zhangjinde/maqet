/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_VAR_HEADER_H
#define MAQET_VAR_HEADER_H

/*
An MQTT variable header structures and functions.
*/

#include <stdio.h>
#include "connect_attr.h"
#include "connect_status.h"

/*
An MQTT variable header structure.
Some types of MQTT command messages also contain a variable header component.
It resides between the fixed header and the payload.
*/
struct var_header {
    /*
    The protocol name is present in the variable header of a MQTT CONNECT
    message. This field is a UTF-encoded string that represents the protocol
    name MQIsdp, capitalized as shown.
    */
    char* protocol_name;

    /*
    The protocol version is present in the variable header of a CONNECT
    message. The value of the Protocol version field for the current version of
    the protocol, 3 (0x03).
    */
    unsigned char protocol_version;

    /* The connection attributes (MQTT Connect flags). */
    struct connect_attr* connect_attr;

    /*
    The Keep Alive timer, measured in seconds, defines the maximum time
    interval between messages received from a client. It enables the server to
    detect that the network connection to a client has dropped, without having
    to wait for the long TCP/IP timeout. The client has a responsibility to
    send a message within each Keep Alive time period.
    */
    unsigned short keep_alive;

    /*
    The connect return code is sent in the variable header of a CONNACK
    message.
    */
    enum connect_status connect_status;

    /*
    The topic name is the key that identifies the information channel to which
    payload data is published. Subscribers use the key to identify the
    information channels on which they want to receive published information.
    */
    char* topic_name;

    /*
    The Message ID must be unique amongst the set of "in flight" messages in a
    particular direction of communication. It typically increases by exactly
    one from one message to the next, but is not required to do so.
    */
    unsigned short message_id;
};

/*
Allocates a variable header.
On success, returns a new variable header, otherwise NULL.
*/
struct var_header* var_header_new();

/*
Deallocates a previously allocated variable header.
@var_header: a previously allocated variable header.
*/
void var_header_free(struct var_header* var_header);

/*
Reads a variable header from a stream.
@stream:
@var_header:
*/
void var_header_read(FILE* stream, struct var_header* var_header);

#endif

