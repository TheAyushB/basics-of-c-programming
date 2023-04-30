#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void enqueue(Queue* q, int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
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

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    int data = q->front->data;
    QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
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
