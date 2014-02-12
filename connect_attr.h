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
    /*
    A connecting client specifies the QoS level in the Will QoS field for a
    Will message that is sent in the event that the client is disconnected
    involuntarily. The Will message is defined in the payload of a CONNECT
    message.
    */
    enum qos qos;

    /*
    If not set (0), then the server must store the subscriptions of the client
    after it disconnects. This includes continuing to store QoS 1 and QoS 2
    messages for the subscribed topics so that they can be delivered when the
    client reconnects. The server must also maintain the state of in-flight
    messages being delivered at the point the connection is lost. This
    information must be kept until the client reconnects.
    
    If set (1), then the server must discard any previously maintained
    information about the client and treat the connection as "clean". The
    server must also discard any state when the client disconnects.
    */
    bool is_clean_session: 1;

    /*
    The MQTT Will flag. Defines that a message is published on behalf of the
    client by the server when either an I/O error is encountered by the server
    during communication with the client, or the client fails to communicate
    within the Keep Alive timer schedule. Sending a Will message is not
    triggered by the server receiving a DISCONNECT message from the client.
    */
    bool is_repeat: 1;

    /*
    The MQTT  Will Retain flag. Indicates whether the server should retain the Will
    message which is published by the server on behalf of the client in the
    event that the client is disconnected unexpectedly.
    */
    bool is_retain: 1;

    /*
    A connecting client can specify a user name and a password, and setting the
    flag bits signifies that a User Name, and optionally a password, are
    included in the payload of a CONNECT message.
    */
    bool is_username: 1;

    /*
    Indicates whether a password is included in the payload.

    If the Password flag is set, the Password field is mandatory, otherwise its
    value is disregarded.
    */
    bool is_password: 1;
};

/*
Allocates an MQTT connection attributes structure.
On success, returns a pointer to a connection attributes structure, otherwise
NULL.
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

