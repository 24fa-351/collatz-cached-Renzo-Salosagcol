#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct{
    unsigned long long data;
    unsigned long long priority;
} Node;

void init_node(Node *node, unsigned long long data, unsigned long long priority);

void print_node(const Node *node);

#endif