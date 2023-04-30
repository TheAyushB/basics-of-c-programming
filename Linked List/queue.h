#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void enqueue(Queue* q, int data);
int dequeue(Queue* q);
void printQueue(Queue* q);

#endif
