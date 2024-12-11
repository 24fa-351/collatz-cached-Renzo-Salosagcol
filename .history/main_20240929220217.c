#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "collatz.h"
#include "cache.h"

int main (int argc, char *argv[]) {
  Config config = configure_parameters(argv);

  char *policy = "lru";
  int cache_size = 10;
  
  Cache cache;
  init_cache(&cache, cache_size, policy);

  FILE *file;
  file = fopen("collatz_results.csv", "w+");
  fprintf(file, "Output Number, Steps To Reach 1, Cache Hit Rate\n");
  
  srand(time(NULL));
    unsigned long long total_steps = 0;
    unsigned long long cache_hits = 0;

    for (unsigned long long i = 0; i < N; i++) {
        unsigned long long RN = MIN + rand() % (MAX - MIN + 1);
        unsigned long long steps = 0;

        if (get_from_cache(&cache, RN, &steps)) {
            cache_hits++;
        } else {
            steps = collatz(RN);
            add_to_cache(&cache, RN, steps);
        }

        total_steps += steps;
        fprintf(file, "%llu, %llu, %d\n", RN, steps, get_from_cache(&cache, RN, &steps));
    }

    fclose(file);
    free_cache(&cache);

    printf("Total steps: %llu\n", total_steps);
    printf("Cache hits: %llu\n", cache_hits);
    printf("Cache hit rate: %.2f%%\n", (double)cache_hits / N * 100);

    return 0;
}