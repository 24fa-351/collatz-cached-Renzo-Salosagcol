#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cache.h"

void init_cache(Cache *cache, int capacity, const char *policy) {
    cache->entries = (CacheEntry *)malloc(capacity * sizeof(CacheEntry));
    cache->size = 0;
    cache->capacity = capacity;
    strncpy(cache->policy, policy, sizeof(cache->policy) - 1);
    cache->policy[sizeof(cache->policy) - 1] = '\0';
    cache->current_index = 0;
}

void add_to_cache(Cache *cache, unsigned long long value, unsigned long long steps) {
    if (cache->size < cache->capacity) {
        cache->entries[cache->size].value = value;
        cache->entries[cache->size].steps = steps;
        cache->entries[cache->size].usage_count = 0;
        cache->size++;
    } else {
        if (strcmp(cache->policy, "lru") == 0) {
            // Implement LRU policy
            int lru_index = 0;
            for (int i = 1; i < cache->size; i++) {
                if (cache->entries[i].usage_count < cache->entries[lru_index].usage_count) {
                    lru_index = i;
                }
            }
            cache->entries[lru_index].value = value;
            cache->entries[lru_index].steps = steps;
            cache->entries[lru_index].usage_count = 0;
        } else if (strcmp(cache->policy, "fifo") == 0) {
            // Implement FIFO policy
            cache->entries[cache->current_index].value = value;
            cache->entries[cache->current_index].steps = steps;
            cache->current_index = (cache->current_index + 1) % cache->capacity;
        }
    }
}

int get_from_cache(Cache *cache, unsigned long long value, unsigned long long *steps) {
    for (int i = 0; i < cache->size; i++) {
        if (cache->entries[i].value == value) {
            *steps = cache->entries[i].steps;
            cache->entries[i].usage_count++;
            return 1;
        }
    }
    return 0;
}

void free_cache(Cache *cache) {
    free(cache->entries);
    cache->size = 0;
    cache->capacity = 0;
    cache->current_index = 0;
}
