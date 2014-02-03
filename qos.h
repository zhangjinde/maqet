/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_QOS_H
#define MAQET_QOS_H

/*
This flag indicates the level of assurance for delivery of a PUBLISH message.
*/
enum qos {
    // Fire and forget.
    at_most_once = 0,

    // Acknowledged delivery.
    at_least_once = 1,

    //Assured delivery.
    exactly_once = 2
);

#endif

