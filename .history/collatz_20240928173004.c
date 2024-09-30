#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) {

    int tests_amount = 10;
    int min = 0;
    int max = 10000;
    
    for (int index = 0; index < tests_amount; index++) {
      // Choose a random number between min and max
      int current_test_num = rand() % (max - min + 1) + min;
      int current_value = current_test_num;
      int steps = 0;

      while 
      printf("test %d: %d \n", index, current_test_num);
    }
    
    //Apply the collatz conjecture
    // If the current_num term is even, the next term is: current_num/2
    // If the current_num is odd, the next term is: (3 * current_num) + 1
    // Eventually this will result in 1

    // Output the original number and the number of steps to get to 1 into a csv file
    // No need for the numbers in between

    // Do this N more times



   return 0;
}