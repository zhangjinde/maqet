/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_STRING_H
#define MAQET_STRING_H

/*
The MQTT string decoding and encoding routines's interface.
*/

#include <stdio.h>

/*
A structure representing an MQTT string.
In MQTT, strings are prefixed with two bytes to denote the length.
*/
struct string {
    unsigned short length;
    char* value;
};

/*
Reads an MQTT string from the stream.
@stream:
@string:
*/
char* string_read(FILE* stream);

/*
Write an MQTT string to the stream.
@stream:
@string:
*/
void string_write(FILE* stream, const char* value); 

#endif

