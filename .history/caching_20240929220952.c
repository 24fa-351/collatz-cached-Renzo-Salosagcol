#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cache.h"

void init_cache(Cache *cache, int capacity, const char *policy) {
    cache->data = (unsigned long long *)malloc(capacity * sizeof(unsigned long long));
    cache->usage = (unsigned long long *)malloc(capacity * sizeof(unsigned long long));
    cache->size = 0;
    cache->capacity = capacity;
    strncpy(cache->policy, policy, sizeof(cache->policy) - 1);
    cache->policy[sizeof(cache->policy) - 1] = '\0';
}

void add_to_cache(Cache *cache, unsigned long long value, unsigned long long steps) {
    if (cache->size < cache->capacity) {
        cache->data[cache->size] = value;
        cache->usage[cache->size] = steps;
        cache->size++;
    } else {
        if (strcmp(cache->policy, "lru") == 0) {
            cache->data[0] = value;
            cache->usage[0] = steps;
        } else if (strcmp(cache->policy, "fifo") == 0) {
            cache->data[0] = value;
            cache->usage[0] = steps;
        }
    }
}

int get_from_cache(Cache *cache, unsigned long long value, unsigned long long *steps) {
    for (int index = 0; index < cache->size; index++) {
        if (cache->data[index] == value) {
            *steps = cache->usage[index];
            // Cache Hit
            return 1;
        }
    }

    // Cache Miss
    return 0;
}

void free_cache(Cache *cache) {
    free(cache->data);
    free(cache->usage);
    cache->size = 0;
    cache->capacity = 0;
}
