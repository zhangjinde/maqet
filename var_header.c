/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
An MQTT variable header implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "var_header.h"
#include "string.h"
#include "connect_attr.h"

//static const char* protocol_name = "MQIsdp";
static const unsigned char protocol_version = 0x03;
static const unsigned char keep_alive_size = 0x02;

struct var_header* var_header_new() {
    return malloc(sizeof(struct var_header));
}

void var_header_free(struct var_header* var_header) {
    assert(var_header);

    free(var_header->topic_name);
    free(var_header->protocol_name);
    free(var_header->connect_attr);
    free(var_header);
}

void var_header_read(FILE* stream, struct var_header* var_header) {
    assert(stream);
    assert(!ferror(stream));
    assert(var_header);

    var_header->protocol_name = string_read(stream);
    var_header->protocol_version = fgetc(stream); 

    var_header->connect_attr = connect_attr_new(); 
    connect_attr_read(stream, var_header->connect_attr);
    
    var_header->keep_alive = ((fgetc(stream) << 0x08) & 0xff00) | (fgetc(stream) & 0x00ff);
    
    // TODO: complete the implementation.
}

