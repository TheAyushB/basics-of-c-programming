#include <stdio.h>
#include <stdlib.h>
// #include "config.h"
#include "../bin/queue.h"

void enqueue(Queue* q, int data) {
    QueueNode* newNode = (QueueNode*)myQMalloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("Error: Unable to allocate memory.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty.\n");
        return;
    }
    int data = q->front->data;
    QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    myQFree(temp);
    printf("Deleted data: %d", data);
    return;
}

void printQueue(Queue* q) {
    printf("Queue: ");
    QueueNode* curr = q->front;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

size_t totalQAllocated = 0;

void *myQMalloc(size_t size)
{
    // Call the standard malloc function to allocate memory
    void *ptr = malloc(size);

    // If the allocation was successful, add the size of the memory block to the total_allocated variable
    if (ptr != NULL)
    {
        totalQAllocated += sizeof(*ptr);
        printf("Allocated %zu bytes of memory at %p\n\n", sizeof(*ptr), ptr);
    }

    printf("Total memory allocated so far: %zu bytes\n\n", totalQAllocated);

    return ptr;
}

size_t totalQFreed = 0;

void myQFree(void *ptr)
{
    // Add the size of the memory being freed to the total_freed variable
    size_t size = sizeof(*ptr);
    totalQFreed += size;

    printf("Freeing %zu bytes of memory at %p\n\n", size, ptr);
    free(ptr);

    printf("Total memory freed so far: %zu bytes\n\n", totalQFreed);
}