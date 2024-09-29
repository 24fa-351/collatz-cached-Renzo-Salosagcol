#include <stdbool.h>
#include <stdint.h>

#ifndef CACHE_H
#define CACHE_H

void cache_init(unsigned long size_of_cache);

bool cache_has(uint64_t candidate);

uint64_t cache_value_for(uint64_t candidate);

void cache_insert(uint64_t candidate, uint64_t value);

void cache_free(void);

#endif