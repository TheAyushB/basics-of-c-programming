#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

void push(StackNode** top, int data);
void pop(StackNode** top);
void printStack(StackNode* top);

void *myMalloc(size_t size);

void myFree(void *ptr);

#endif
