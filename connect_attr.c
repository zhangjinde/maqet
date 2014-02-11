/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

/*
An MQTT connection attributes implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "connect_attr.h"
#include "qos.h"

static const unsigned char connect_attr_size = 0x01;

struct connect_attr* connect_attr_new() {
    return malloc(sizeof(struct connect_attr));
}

void connect_attr_free(struct connect_attr* connect_attr) {
    assert(connect_attr);

    free(connect_attr);
}

void connect_attr_read(FILE* stream, struct connect_attr* connect_attr) {
    assert(stream);
    assert(!ferror(stream));
    assert(connect_attr);

    char octet = fgetc(stream);
    connect_attr->username = octet >> 7 & 0x01;
    connect_attr->password = octet >> 6 & 0x01;
    connect_attr->retain = octet >> 5 & 0x01;
    connect_attr->qos = octet >> 3 & 0x03;
    connect_attr->will = octet >> 2 & 0x01;
    connect_attr->clean_session = octet >> 1 & 0x01;
}

