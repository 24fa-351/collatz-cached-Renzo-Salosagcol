#include <stdio.h>
#include <stdlib.h>

#include "collatz.h"
#include "config.h"
#include "cache.h"

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
      int current_test_num = config.min + rand() % (config.max + config.min);
      int current_value = current_test_num;
      int steps = 0;

      while (current_value != 1) {

        if (current_value % 2 == 0) {
          // If even: cut in half
          current_value /= 2;
        } else { 
          // If odd: multiple by 3 and add 1 for the next term
          current_value = (current_value * 3) + 1;
        }

        steps++;
      }

      average_steps += steps;
      fprintf(file, "\n%d, %d", current_test_num, steps);
    }

    fclose(file);

    average_steps /= TESTS_AMOUNT;
    printf("Average Steps: %d", average_steps);

   return 0;
}