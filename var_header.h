/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_VAR_HEADER_H
#define MAQET_VAR_HEADER_H

/*
A variable header structires and functions.
*/

struct var_header {
    char* protocol_name;
    unsigned char protocol_version;
    enum connect_flag connect_flag;
    unsigned short keep_alive;
    enum connect_status connect_status;
    char* topic_name;
    unsigned short message_id;
};

void var_header_read(FILE* stream, struct var_header* var_header);

#endif

