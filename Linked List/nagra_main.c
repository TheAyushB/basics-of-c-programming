#include <stdio.h>
#include <stdlib.h>
#include "linear_list.h"


int main()
{
    LIST *linkedList = createList();

    addNode(linkedList, 56);
    printList(linkedList);

    return 0;
}
