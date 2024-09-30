#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "collatz.h"
#include "caching.h"
#include "node.h"

unsigned long long caching_wrapper (unsigned long long starting_value, char *policy, int cache_size) {
  unsigned long long steps = 0;

  // printf("Policy: %s\n", policy);

  if (strcmp(policy,"none") == 0) {
    steps = collatz(starting_value);
  } else if (strcmp(policy,"lru") == 0) {
    // printf("LRU initiated\n");
    steps = least_recently_used(starting_value, cache_size);
  } else if (strcmp(policy,"fifo") == 0) {
    // printf("FIFO initiated\n");
    steps = first_in_first_out(starting_value, cache_size);
  } else {
    printf("Error in policy reading");
    return steps;
  }

  return steps;
}

int main (int argc, char *argv[]) {
  Config config = configure_parameters(argv);

  char *policy = "lru";
  int cache_size = 10;
  Node arr[cache_size];

  FILE *file;
  file = fopen("collatz_results.csv", "w+");
  fprintf(file, "Output Number, Steps To Reach 1");
  
  for (unsigned long long index = 0; index < config.tests_num; index++) {
    // Choose a random number between min and max
    unsigned long long starting_value = rand() % (config.max - config.min + 1) + config.min;
    unsigned long long steps = caching_wrapper(starting_value, policy, cache_size);

    fprintf(file, "\n%d, %d", starting_value, steps);
  }

  fclose(file);

  return 0;
}