#include <stdio.h>

#include "caching.h"
#include "node.h"

unsigned long long least_recently_used (unsigned long long starting_value, int cache_size) {
  Node arr[cache_size];
  for (int index = 0; index < cache_size; index++) {
    init_node(&arr[index],index, 0);
  }

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
    
    int minIndex = 0;
    for (int index = 0; index < cache_size; index++) {
      if (get_priority(&arr[index]) == 0) {
        minIndex = index;
        break;
      } else if (get_priority(&arr[index]) < get_priority(&arr[minIndex])) {
        minIndex = index;
      }
    }
    init_node(&arr[minIndex],starting_value, steps);
  }

  return steps;
}

unsigned long long first_in_first_out (unsigned long long starting_value, int cache_size) {
  Node queue[cache_size];
  for (int index = 0; index < cache_size; index++) {
    init_node(&queue[index], 0, index);
  }

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
    
    for (int index = 0; index < cache_size; index++) {
      if (get_data(&queue[index]) == 0) {
        init_node(&queue[index], starting_value, index);
      }
    }
  }

  return steps;
}