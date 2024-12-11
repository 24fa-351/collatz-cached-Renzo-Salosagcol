#include <stdio.h>
#include "node.h"

void init_node(Node *node, unsigned long long coll_num, unsigned long long steps) {
  node->coll_num = coll_num;
  node->steps = steps;
}

void print_node(const Node *node) {
  printf("Ollatz Number: %llu, Steps: %llu\n", node->coll_num, node->steps);
}

unsigned long long get_coll_num(const Node *node) {
  return node->coll_num;
}

unsigned long long get_steps(const Node *node) {
  return node->steps;
}