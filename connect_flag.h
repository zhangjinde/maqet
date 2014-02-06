/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_CONNECT_FLAG_H
#define MAQET_CONNECT_FLAG_H

/*
A connection flag enumeration.
*/
enum connect_flag {
    username = 1,
    password = 1 << 1,
    will_retain = 1 << 2,
    will_qos = 1 << 3,
    will_flag = 1 << 4,
    clean_session = 1 << 5
};

#endif

