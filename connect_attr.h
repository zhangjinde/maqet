/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_CONNECT_ATTR_H
#define MAQET_CONNECT_ATTR_H

/*
An MQTT connection attributes structures and functions.
*/

#include <stdio.h>
#include <stdbool.h>
#include "connect_attr.h"
#include "qos.h"

/*
An MQTT connection attributes structure.
*/
struct connect_attr {
    enum qos qos;
    bool clean_session: 1;
    bool will: 1;
    bool retain: 1;
    bool username: 1;
    bool password: 1;
};

/*
Allocates an MQTT connection attributes structure.
On success, returns a pointer to a connection attributes structure, otherwise NULL.
*/
struct connect_attr* connect_attr_new();

/*
Deallocates a previously allocated connection attributes structure.
@connect_attr: a previously allocated connection attributes structure.
*/
void connect_attr_free(struct connect_attr* connect_attr);

/*
Reads a connection attributes structure from the supplied stream.
@stream:
@connect_attr:
*/
void connect_attr_read(FILE* stream, struct connect_attr* connect_attr);

#endif

