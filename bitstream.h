#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <stdbool.h>

typedef struct {
    char *data;
    int byte;
    int bit;
} bitstream_reader;

bool bsr_bit(bitstream_reader *r) {
    bool bit = (r->data[r->byte] >> r->bit++) & 1;
    // if we went past the end of the byte, go to the next byte
    if (r->bit > 7) {
        r->bit = 0;
        r->byte++;
    }
    return bit;
}

#endif // BITSTREAM_H
