#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

void push(StackNode** top, int data);
void pop(StackNode** top);
void printStack(StackNode* top);

void *mySMalloc(size_t size);

void mySFree(void *ptr);

#endif
