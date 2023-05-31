#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void push(StackNode** top, int data) {
    StackNode* newNode = (StackNode*)mySMalloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Error: Unable to allocate memory.\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

void pop(StackNode** top) {
    if (*top == NULL) {
        printf("Error: Stack is empty.\n");
        return;
    }
    int data = (*top)->data;
    StackNode* temp = *top;
    *top = (*top)->next;
    mySFree(temp);
    printf("Data popped is: %d\n", data);
    return;
}

void printStack(StackNode* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}


size_t totalSAllocated = 0;

void *mySMalloc(size_t size)
{
    // Call the standard malloc function to allocate memory
    void *ptr = malloc(size);

    // If the allocation was successful, add the size of the memory block to the total_allocated variable
    if (ptr != NULL)
    {
        totalSAllocated += sizeof(*ptr);
    }

    printf("Total memory allocated so far: %zu bytes\n\n", totalSAllocated);

    return ptr;
}

size_t totalSFreed = 0;

void mySFree(void *ptr)
{
    // Add the size of the memory being freed to the total_freed variable
    size_t size = sizeof(*ptr);
    totalSFreed += size;

    free(ptr);

    printf("Total memory freed so far: %zu bytes\n\n", totalSFreed);
}