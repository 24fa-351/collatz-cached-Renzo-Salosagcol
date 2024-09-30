#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "collatz.h"
#include "caching.h"

int main (int argc, char *argv[]) {
  Config config = configure_parameters(argv);

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