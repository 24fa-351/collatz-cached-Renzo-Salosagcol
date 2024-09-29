#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) {
    int tests_amount = 10;
    int min = 0;
    int max = 10000;

    FILE *file;
    file = fopen("collatz_results.csv", "w+");
    fprintf(file, "Output Number, Steps To Reach 1");
    
    for (int index = 0; index < tests_amount; index++) {
      // Choose a random number between min and max
      int current_test_num = rand() % (max - min + 1) + min;
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

      fprintf(file, "\n%d, %d", current_test_num, steps);
    }

    fclose(file);

   return 0;
}