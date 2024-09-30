#ifndef CACHING_H
#define CACHING_H

unsigned long long least_recently_used (unsigned long long starting_value, int cache_size);
unsigned long long first_in_first_out (unsigned long long starting_value, int cache_size);

#endif