/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_VAR_HEADER_H
#define MAQET_VAR_HEADER_H

/*
A variable header structires and functions.
*/

#include "connect_flag.h"
#include "connect_status.h"

struct var_header {
    const char* protocol_name;
    unsigned char protocol_version;
    enum connect_flag connect_flag;
    unsigned short keep_alive;
    enum connect_status connect_status;
    char* topic_name;
    unsigned short message_id;
};

/*
Allocates a variable header.
On success, returns a new variable header, otherwise NULL.
*/
struct var_header* var_header_new();

/*
Deallocates a previously allocated variable header.
@message: a previously allocated variable header.
*/
void var_header_free(struct var_header* var_header);

void var_header_read(FILE* stream, struct var_header* var_header);

#endif

