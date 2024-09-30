#include <stdio.h>
#include "node.h"

void init_node(Node *node, unsigned long long coll_num, unsigned long long steps) {
  node->coll_num = coll_num;
  node->priority = priority;
}

void print_node(const Node *node) {
  printf("Ollatz Number: %llu, Priority: %llu\n", node->coll_num, node->priority);
}

unsigned long long get_coll_num(const Node *node) {
  return node->coll_num;
}

unsigned long long get_priority(const Node *node) {
  return node->priority;
}