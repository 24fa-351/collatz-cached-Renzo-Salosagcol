#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "collatz.h"


unsigned long long caching_wrapper (unsigned long long starting_value, char policy[], int cache_size) {
  unsigned long long steps = 0;

  if (policy == "none") {
    steps = collatz(starting_value);
  } else if (policy == "LRU") {
    steps = collatz(starting_value);
  } else if (policy == "FIFO") {
    steps = collatz(starting_value);
  } else {
    return steps;
  }

  return steps;
}

int main (int argc, char *argv[]) {
  Config config = configure_parameters(argv);

  char policy[] = "none";
  int char_size = 10;

  FILE *file;
  file = fopen("collatz_results.csv", "w+");
  fprintf(file, "Output Number, Steps To Reach 1");
  
  for (unsigned long long index = 0; index < config.tests_num; index++) {
    // Choose a random number between min and max
    unsigned long long starting_value = rand() % (config.max - config.min + 1) + config.min;
    unsigned long long steps = collatz(starting_value);

    fprintf(file, "\n%d, %d", starting_value, steps);
  }

  fclose(file);

  return 0;
}