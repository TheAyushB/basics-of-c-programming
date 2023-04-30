#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

void push(StackNode** top, int data);
int pop(StackNode** top);
void printStack(StackNode* top);

#endif
