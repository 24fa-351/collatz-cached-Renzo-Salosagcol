#ifndef CACHE_H
#define CACHE_H

typedef struct {
    unsigned long long *data;
    unsigned long long *usage;
    int size;
    int capacity;
    char policy[10];
} Cache;

void init_cache(Cache *cache, int capacity, const char *policy);
void add_to_cache(Cache *cache, unsigned long long value, unsigned long long steps);
int get_from_cache(Cache *cache, unsigned long long value, unsigned long long *steps);
void free_cache(Cache *cache);

#endif
