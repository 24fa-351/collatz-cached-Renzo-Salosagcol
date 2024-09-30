#include <stdio.h>
#include <stdlib.h>

#include "collatz.h"
#include "config.h"
// #include "cache.h"

typedef unsigned long long ull;

int main (int argc, char *argv[]) {
    Config config = create_config(argv);

    FILE *file;
    file = fopen("collatz_results.csv", "w+");
    fprintf(file, "Output Number, Steps To Reach 1");
    
    for (ull index = 0; index < config.tests_num; index++) {
      // Choose a random number between min and max
      ull starting_value = config.min + rand() % (config.max + config.min);

      ull steps = collatz(starting_value);

      fprintf(file, "\n%llu, %llu", starting_value, steps);
    }

    fclose(file);

   return 0;
}