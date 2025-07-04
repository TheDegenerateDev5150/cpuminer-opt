#ifndef RIPEMD_HASH_4WAY_H__
#define RIPEMD_HASH_4WAY_H__

#include <stddef.h>

#if defined(__SSE4_2__)

#include "simd-utils.h"

typedef struct
{
   __m128i buf[64>>2];
   __m128i val[5];
   uint32_t count_high, count_low;
} __attribute__ ((aligned (64))) ripemd160_4x32_context;

void ripemd160_4x32_init( ripemd160_4x32_context *sc );
void ripemd160_4x32_update( ripemd160_4x32_context *sc, const void *data,
                            size_t len );
void ripemd160_4x32_close( ripemd160_4x32_context *sc, void *dst );

#if defined (__AVX2__)

typedef struct
{
   __m256i buf[64>>2];
   __m256i val[5];
   uint32_t count_high, count_low;
} __attribute__ ((aligned (128))) ripemd160_8x32_context;

void ripemd160_8x32_init( ripemd160_8x32_context *sc );
void ripemd160_8x32_update( ripemd160_8x32_context *sc, const void *data,
                            size_t len );
void ripemd160_8x32_close( ripemd160_8x32_context *sc, void *dst );

#if defined(SIMD512)

typedef struct
{
   __m512i buf[64>>2];
   __m512i val[5];
   uint32_t count_high, count_low;
} __attribute__ ((aligned (128))) ripemd160_16x32_context;

void ripemd160_16x32_init( ripemd160_16x32_context *sc );
void ripemd160_16x32_update( ripemd160_16x32_context *sc, const void *data,
                      size_t len );
void ripemd160_16x32_close( ripemd160_16x32_context *sc, void *dst );

#endif // AVX512
#endif // __AVX2__
#endif // __SSE4_2__
#endif // RIPEMD_HASH_4WAY_H__
