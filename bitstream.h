#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <stdbool.h>

typedef struct {
    unsigned char *data;
    long byte;
    unsigned char bit;
} bitstream_reader;

bool bsr_bit(bitstream_reader *r) {
    bool bit = (r->data[r->byte] >> r->bit++) & 1;
    r->byte += r->bit >> 3;
    r->bit &= 0b111;
    return bit;
}

unsigned char bsr_byte(bitstream_reader *r) {
    return r->data[r->byte] >> r->bit | r->data[++r->byte] << (8 - r->bit);
}

#endif // BITSTREAM_H
