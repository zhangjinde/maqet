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
*/
struct var_header {
    char* protocol_name;
    unsigned char protocol_version;
    struct connect_attr* connect_attr;
    unsigned short keep_alive;

    /*
    The connect return code is sent in the variable header of a CONNACK
    message.
    */
    enum connect_status connect_status;
    char* topic_name;
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

