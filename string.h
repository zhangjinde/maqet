/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_STRING_H
#define MAQET_STRING_H

/*
The MQTT string encoding routines's interface.
*/

/*
A structure representing an MQTT string.
In MQTT, strings are prefixed with two bytes to denote the length.
*/
struct string {
    unsigned short length;
    char* value;
}

void string_encode(char* value, struct string* string);

void string_decode(const struct string* string, const char* value); 

#endif

