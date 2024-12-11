#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct{
    int data;
    struct Node* next;
} Node;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

#endif