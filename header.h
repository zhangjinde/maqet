/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_HEADER_H
#define MAQET_HEADER_H

/*
A message header.
*/
struct header {
    unsigned char type: 4;
    unsigned char dup: 1;
    unsigned char qos: 2;
    unsigned char retain: 1;
    unsigned char size;
};

#endif

