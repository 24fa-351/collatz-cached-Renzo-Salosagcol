#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
  
  unsigned long long total_steps = 0;
  unsigned long long cache_hits = 0;

  for (int test_index = 0; test_index < config.tests_num; test_index++) {
      unsigned long long rand_test_value = config.min + rand() % (config.max - config.min + 1);
      unsigned long long steps = 0;

      if (get_from_cache(&cache, rand_test_value, &steps)) {
          cache_hits++;
      } else {
          steps = collatz(rand_test_value);
          add_to_cache(&cache, rand_test_value, steps);
      }

      total_steps += steps;
      fprintf(file, "%llu, %llu, %d\n", rand_test_value, steps, get_from_cache(&cache, rand_test_value, &steps));
  }

  fclose(file);
  free_cache(&cache);

  return 0;
}