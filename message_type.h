/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_MESSAGE_TYPE_H
#define MAQET_MESSAGE_TYPE_H

/*
A message type.
*/
enum message_type {
    unknown = 0,
    connect = 1,
    connection_ack = 2,
    publish = 3,
    publish_ack = 4,
    publish_received = 5,
    publish_release = 6,
    publish_complete = 7,
    subscribe = 8,
    subscribe_ack = 9,
    unsubscribe = 10,
    unsubscribe_ack = 11,
    ping_request = 12,
    ping_response = 13,
    disconnect = 14
};

#endif

