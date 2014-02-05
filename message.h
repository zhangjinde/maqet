/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_MESSAGE_H
#define MAQET_MESSAGE_H

/*
The message interface.
*/

struct message {
    struct fixed_header* fixed_header;
    struct var_header* var_header;
    struct payload* payload;
}

#endif

