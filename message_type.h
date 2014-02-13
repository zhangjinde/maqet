/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_MESSAGE_TYPE_H
#define MAQET_MESSAGE_TYPE_H

/*
The MQTT Message type.
*/
enum message_type {
    /* An unknown message type. */
    unknown = 0x00,

    /* A client requests a connection to a server. */ 
    connect = 0x01,

    /* A server acknowledges a connection request. */
    connect_ack = 0x02,

    publish = 0x03,
    publish_ack = 0x04,
    publish_received = 0x05,
    publish_release = 0x06,
    publish_complete = 0x07,
    subscribe = 0x08,
    subscribe_ack = 0x09,
    unsubscribe = 0x0a,
    unsubscribe_ack = 0x0b,
    ping_request = 0x0c,
    ping_response = 0x0d,
    disconnect = 0x0f
};

#endif

