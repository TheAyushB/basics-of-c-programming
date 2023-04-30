#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(StackNode** top, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Error: Unable to allocate memory.\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(StackNode** top) {
    if (*top == NULL) {
        printf("Error: Stack is empty.\n");
        return -1;
    }
    int data = (*top)->data;
    StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

void printStack(StackNode* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}
