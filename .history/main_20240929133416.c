#include <stdio.h>
#include <stdlib.h>

#include "collatz.h"
#include "config.h"
// #include "cache.h"

unsigned int caching_wrapper(unsigned int num, char[] policy, int cache_size) {
  


  return steps;
}

int main (int argc, char *argv[]) {
    Config config = create_config(int argc, char *argv[]);

    FILE *file;
    file = fopen("collatz_results.csv", "w+");
    fprintf(file, "Output Number, Steps To Reach 1");
    
    for (int index = 0; index < config.tests_num; index++) {
      // Choose a random number between min and max
      int starting_value = config.min + rand() % (config.max + config.min);
      int steps = collatz(starting_value);
      fprintf(file, "\n%d, %d", starting_value, steps);
    }

    fclose(file);

   return 0;
}