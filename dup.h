/*
Project maqet.
Copyright (C) 2014, Roman Fakhrazeyev, <roman.fakhrazeyev@two718.com>
*/

#ifndef MAQET_DUP_H
#define MAQET_DUP_H

/*
This flag is set when the client or server attempts to re-deliver 
a PUBLISH, PUBREL, SUBSCRIBE or UNSUBSCRIBE message. This applies to messages 
where the value of QoS is greater than zero (0), and an acknowledgment 
is required. When the DUP bit is set, the variable header includes a Message ID.
*/
enum dup {
    none = 0,
    attempt = 1
);

#endif

