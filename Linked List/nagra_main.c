#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linear_list.h"
#include "config.h"

#if defined(IMPLEMENT_STACK)
#include "stack.h"
#elif defined(IMPLEMENT_QUEUE)
#include "queue.h"
#else(IMPLEMENT_LINEAR_LIST)

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

    return 0;
}