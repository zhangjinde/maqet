/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_PROTOCOL_H
#define MAQET_PROTOCOL_H

/*
The protocol interface.
*/

#include <stdio.h>
#include "message.h"

void protocol_read(FILE* stream, struct message* message);

#endif

