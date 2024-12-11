#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct{
    unsigned long long data;
    struct Node* next;
} Node;

struct Node* createNode(unsigned long long data);

#endif