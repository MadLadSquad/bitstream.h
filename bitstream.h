#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint64_t *ptr;
    unsigned char bit;
} bit_reader;

// Read one (1) bit
bool bsr1(bit_reader *r) {
    bool bit = (*r->ptr >> r->bit++) & 1;
    r->ptr += r->bit >> 6;
    r->bit &= 0x3f;
    return bit;
}

uint64_t bsr64(bit_reader *r) {
    return *r->ptr >> r->bit | *++r->ptr << (63 - r->bit);
}

#endif // BITSTREAM_H
