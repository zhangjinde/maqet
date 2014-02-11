/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_PROTOCOL_H
#define MAQET_PROTOCOL_H

/*
An MQTT protocol interface.
*/

#include <stdio.h>
#include "message.h"

/*
Reads an MQTT protocol message from the supplied stream.
@stream:
@message:
*/
void protocol_message_read(FILE* stream, struct message* message);

#endif

