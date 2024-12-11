#include "caching.h"
#include "node.h"

unsigned long long least_recently_used (unsigned long long starting_value, int cache_size) {
  return 0;
}

unsigned long long first_in_first_out (unsigned long long starting_value, int cache_size) {
  Node queue[cache_size];
  unsigned long long steps = 0;

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

  return 0;
}