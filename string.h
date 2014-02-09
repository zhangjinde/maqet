/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_STRING_H
#define MAQET_STRING_H

/*
The MQTT string encoding routines's interface.
*/

#include <stdio.h>

/*
A structure representing an MQTT string.
In MQTT, strings are prefixed with two bytes to denote the length.
*/
struct string {
    unsigned short length;
    char* value;
}

void string_read(FILE* stream, const struct string* string)

void string_write(FILE* stream, const char* value); 

#endif

