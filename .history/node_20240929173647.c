#include <stdio.h>
#include "node.h"

void init_node(Node *node, unsigned long long data, unsigned long long priority) {
  node->data = data;
  node->priority = 0;
}

void print_node(const Node *node) {
  printf("Data: %llu, Priority: %llu", node->data, node->priority);
}