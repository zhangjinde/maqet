/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_CONNECT_STATUS_H
#define MAQET_CONNECT_STATUS_H

/*
The MQTT Connection return codes.
The connect return code is sent in the variable header of a CONNACK message.
*/
enum connect_status {
    /* Connection Accepted. */
    accepted = 0x00,

    /* Connection Refused: unacceptable protocol version. */
    unacceptable_version = 0x01,

    /* Connection Refused: identifier rejected. */
    rejected_identifier = 0x02,

    /* Connection Refused: server unavailable. */
    server_unavailable = 0x03,

    /* Connection Refused: bad user name or password. */
    bad_credentials = 0x04,

    /* Connection Refused: not authorized. */
    not_authorized = 0x05
};

#endif

