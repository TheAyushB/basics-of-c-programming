#include <stdio.h>
#include <stdlib.h>
#include "./linear_list/src/linear_list.h" 
#include "./queue/src/queue.h" 
#include "./stack/src/stack.h" 

int main()
{

    #ifdef ENABLE_FEATURE_LINEAR_LIST

    LIST *linkedList = createList();
    addNode(linkedList,56);
    addNode(linkedList,79);
    addNode(linkedList,80);
    addNode(linkedList,12);
    deleteNode(linkedList,79);
    printList(linkedList);
    deleteList(linkedList);

    #endif

   ////////////////////////////////////////////////////////////////////////////////// 
    
    #ifdef ENABLE_FEATURE_QUEUE
    
    Queue *q = (Queue *) malloc(sizeof(Queue));
    if (q == NULL){
        printf("ERROR: malloc failed -> Unable to allocate memory");
        return 1;
    }

    enqueue(q,56);
    enqueue(q,79);
    enqueue(q,80);
    printQueue(q);
    
    #endif
    

    // #ifdef ENABLE_FEATURE_STACK

    StackNode* top = NULL;

    // Push elements onto the stack
        push(&top, 10);
        push(&top, 20);
        push(&top, 30);

    // Print the stack
        printStack(top);

    // Pop an element from the stack
        pop(&top);

    // Print the updated stack
        printStack(top);
    
    // #endif

/////////////////////////////////////////////////////////////////////////////////////////////


    return 0;
}