#include <stdio.h>
#include <stdlib.h>
#include "linear_list.h"
#include <malloc.h>


struct node
{                      // designing node for linked list using structure
    int value;         // value part of the node
    struct node *next; // pointer of node-type containing address of next node
};                     // address of first node

struct list
{
    NODE *head; // address of head node
    NODE *tail; // address of tail node
};

NODE *createNode(int value)
{
    NODE *newNode = (NODE *)myMalloc(sizeof(NODE)); // new node (type casting)
    if (!newNode)
        return NULL; // out of memory

    newNode->value = value; // set value
    newNode->next = NULL;   // create
    return newNode;         // return pointer to new node in the list of nodes
}

LIST *createList()
{
    LIST *newList = (LIST *)myMalloc(sizeof(LIST));
    if (!newList) // out of memory
        return NULL;

    newList->head = NULL; // create list of nodes with value 0 and length 0 and head is NULL
    newList->tail = NULL; // create list of nodes with value 0 and length 0 and tail is NULL
    return newList;
}

void printList(LIST *list)
{
    NODE *temp = list->head; //  pointer to head node
    while (temp)
    { // loop through nodes and print
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void addNode(LIST *list, int value)
{

    void (*function_pointer)(int);
    function_pointer = nodeAddedCallback;
    NODE *newNode = createNode(value);
    if (!newNode) // out of memory
        return;

    if (!list->head)
    {
        list->head = newNode;
        list->tail = newNode;
        return function_pointer(value);
    }

    NODE *current = list->head;
    while (current->next)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
    list->tail = newNode;
    return function_pointer(value);
}

void deleteNode(LIST *list, int value)
{
    NODE *current = list->head;
    NODE *prev = NULL;
    while (current)
    {
        if (current->value == value)
        {
            if (prev)
                prev->next = current->next;
            else
                list->head = current->next;
            myFree(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    return;
}

void deleteList(LIST *list)
{
    NODE *current = list->head;
    while (current)
    {
        NODE *temp = current;
        current = current->next;
        myFree(temp);
    }
    myFree(list);
    return;
}

void reverseList(LIST *list)
{
    NODE *current = list->head;
    NODE *prev = NULL;
    NODE *next = NULL;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
    list->tail = current;
    return;
}

void nodeAddedCallback(int value)
{
    printf("New node added with value: %d\n", value);
}

// Wrapper Functions
size_t totalAllocated = 0;

void *myMalloc(size_t size)
{
    // Call the standard malloc function to allocate memory
    void *ptr = malloc(size);

    // If the allocation was successful, add the size of the memory block to the total_allocated variable
    if (ptr != NULL)
    {
        totalAllocated += sizeof(*ptr);
        printf("Allocated %zu bytes of memory at %p\n", sizeof(*ptr), ptr);
    }

    printf("Total memory allocated so far: %zu bytes\n", totalAllocated);

    return ptr;
}
size_t totalFreed = 0;

void myFree(void *ptr)
{
    // Add the size of the memory being freed to the total_freed variable
    size_t size = sizeof(*ptr);
    totalFreed += size;

    printf("Freeing %zu bytes of memory at %p\n", size, ptr);
    free(ptr);

    printf("Total memory freed so far: %zu bytes\n", totalFreed);
}