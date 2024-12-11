#include <stdio.h>

#include "caching.h"
#include "node.h"

unsigned long long least_recently_used (unsigned long long starting_value, int cache_size) {

  Node arr[cache_size];

  for (int index = 0; index < cache_size; index++) {
    if (&arr[index] == NULL) {
      // Assign any Null values
      init_node(&arr[index], starting_value, 0, 0);
    } else if (&arr[index] != NULL) {
      // Cache Hit
      if (get_coll_num(&arr[index]) == starting_value) {
        increase_util(&arr[index]);
        return get_steps(&arr[index]);
      } 
    } 
  }

  // Checks for possible Cache hit
  for (int index = 0; index < cache_size; index++) {
    
  }

  // Cache Miss

  // Find Least Used
  int minUtilIndex = 0;
  for (int index = 0; index < cache_size; index++) {
    if (get_util(&arr[index]) < get_util(&arr[minUtilIndex])) {
      minUtilIndex = index;
    }
  }

  init_node(&arr[minUtilIndex], starting_value, 0, 0);

  unsigned long long steps = 0;

  while (starting_value != 1) {

    if (starting_value % 2 == 0) {
      // If even: cut in half
      starting_value /= 2;
    } else { 
      // If odd: multiple by 3 and add 1 for the next term
      starting_value = (starting_value * 3) + 1;
    }
  }

  set_steps(&arr[minUtilIndex], steps);

  return steps;
}

unsigned long long first_in_first_out (unsigned long long starting_value, int cache_size) {
  Node queue[cache_size];
  
  int avail_index = 0;
  for (int index = 0; index < cache_size; index++) {
    if (&queue[index] == NULL) {
      // Assign any Null values
      init_node(&queue[index], 0, 0, index);
    } else if (&queue[index] != NULL) {
      // Cache Hit
      if (get_coll_num(&queue[index]) == starting_value) {
        return get_steps(&queue[index]);
      } 
    }
  }

  // Checks for open spaces in queue and replaces it
  for (int index = 0; index < cache_size; index++) {
    if (get_coll_num(&queue[index]) == 0) {
      avail_index = index;
      init_node(&queue[avail_index], starting_value, 0, index);
      break;
    } 
  }

  // Moves every node up by 1 index and frees the last
  if (avail_index = 0) {
    for (int index = 0; index < cache_size - 1; index++) {
      init_node(&queue[index], get_coll_num(&queue[index + 1]), get_steps(&queue[index + 1]), index);
    }
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

    if (get_data(&queue[--cache_size]) == 0) {
      // Loops until the first available index
      for (int index = 0; index < cache_size; index++) {
        if (get_data(&queue[index]) == 0) {
          init_node(&queue[index], starting_value, index);
          break;
        }
      }
    } else if (get_data(&queue[--cache_size]) != 0) {
      // Moves every data up by 1 index
      for (int index = 0; index < cache_size - 1; index++) {
        init_node(&queue[index], get_data(&queue[index++]), index);
      }

      // Changes last index to current value
      init_node(&queue[cache_size - 1], starting_value, cache_size - 1);

    } else {
      printf("Error: FIFO changing");
    }
  }

  return steps;
}