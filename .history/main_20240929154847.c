#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "collatz.h"

int main (int argc, char *argv[]) {
  Config config = configure_parameters(argv);

  FILE *file;
  file = fopen("collatz_results.csv", "w+");
  fprintf(file, "Output Number, Steps To Reach 1");
  
  for (int index = 0; index < config.tests_num; index++) {
    // Choose a random number between min and max
    int starting_value = rand() % (config.max - config.min + 1) + config.min;
    int steps = 0;

    while (starting_value != 1) {

      if (starting_value % 2 == 0) {
        // If even: cut in half
        starting_value /= 2;
      } else { 
        // If odd: multiple by 3 and add 1 for the next term
        starting_value = (starting_value * 3) + 1;
      }

      steps++;
    }

    fprintf(file, "\n%d, %d", starting_value, steps);
  }

  fclose(file);

  return 0;
}