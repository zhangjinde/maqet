#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
}

static void socket() {
}

static void stream() {
    FILE* stream = fopen("/Users/fakhrazeyev/temp/b", "w+b");
    unsigned char buffer[] = { 0x10, 0x0f, 0x00, 0x06, 'M', 'Q', 'I', 's', 'd', 'p', 0x03, 0x0a, 0x00, 0x3c, 0x00, 0x01, 0x63 };
    size_t size = sizeof buffer;
    size_t write_count = fwrite(buffer, sizeof(unsigned char), size, stream);
    fclose(stream);
}

