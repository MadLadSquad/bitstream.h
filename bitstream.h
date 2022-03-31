#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <stdbool.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef struct {
    u8 *data;
    long byte;
    unsigned char bit;
} bitstream_reader;

bool bsr_bit(bitstream_reader *r) {
    bool bit = (r->data[r->byte] >> r->bit++) & 1;
    r->byte += r->bit >> 3;
    r->bit &= 0b111;
    return bit;
}

u8 bsr8(bitstream_reader *r) {
    return r->data[r->byte] >> r->bit | r->data[++r->byte] << (8 - r->bit);
}

u16 bsr16(bitstream_reader *r) {
    u16 a = bsr8(r);
    u16 b = bsr8(r) << 7;
    return a | b;
}

u32 bsr32(bitstream_reader *r) {
    u32 a = bsr16(r);
    u32 b = bsr16(r) << 15;
    return a | b;
}

u64 bsr64(bitstream_reader *r) {
    u64 a = bsr32(r);
    u64 b = bsr32(r) << 31;
    return a | b;
}

#endif // BITSTREAM_H
