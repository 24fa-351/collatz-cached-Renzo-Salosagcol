#include <stdio.h>
#include "node.h"

void init_node(Node *node, unsigned long long data, unsigned long long priority) {
  node->coll_num = data;
  node->priority = priority;
}

void print_node(const Node *node) {
  printf("Data: %llu, Priority: %llu\n", node->data, node->priority);
}

unsigned long long get_data(const Node *node) {
  return node->data;
}

unsigned long long get_priority(const Node *node) {
  return node->priority;
}