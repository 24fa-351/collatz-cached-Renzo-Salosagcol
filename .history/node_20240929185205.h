#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct{
    unsigned long long coll_num;
    unsigned long long steps;
    int index;
} Node;

void init_node(Node *node, unsigned long long coll_num, unsigned long long steps, int index);

void print_node(const Node *node);

unsigned long long get_coll_num(const Node *node);

unsigned long long get_steps(const Node *node);

void set_steps(const Node *node, unsigned long long steps);

#endif