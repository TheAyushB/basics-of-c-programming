#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linear_list.h"
#include "config.h"
#include "stack.h"
#include "queue.h"

#if defined(STACK)
    #include "stack.h"
#elif defined(QUEUE)
    #include "queue.h"
#elif defined(LINEAR_LIST)
    #include "linear_list.h"
#endif

int main()
{
    LIST *linkedList = createList();
    addNode(linkedList, 56);
    addNode(linkedList, 79);
    addNode(linkedList, 29);
    printList(linkedList);
    deleteNode(linkedList, 79);
    printList(linkedList);
    reverseList(linkedList);
    printList(linkedList);

    Queue *queue;
    enqueue(queue, 12);
    enqueue(queue, 24);
    enqueue(queue, 36);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);

    StackNode *stack;
    push(stack, 45);
    push(stack, 56);
    printStack(stack);
    push(stack, 48);
    push(stack, 95);
    printStack(stack);
    pop(stack);
    printStack(stack);

    return 0;
}