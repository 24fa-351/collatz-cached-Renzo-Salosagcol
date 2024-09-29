#include <stdio.h>
#include "collatz.h"

typedef unsigned long long ull;

ull collatz (ull current_value) {
  ull steps = 0;

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
      
  return steps;
}