#ifndef LINEAR_LIST_H_INCLUDED
#define LINEAR_LIST_H_INCLUDED

typedef struct node NODE;

typedef struct list LIST;

NODE *createNode(int value);    // create a node with the specified value
LIST *createList();             // create a list with the specified value and the specified length

void printList(LIST *list);                                 // print the list
void addNode(LIST *list, int value);    // add a node with the specified value
void deleteNode(LIST *list, int value);                     // delete a node with the specified value
void deleteList(LIST *list);                                // delete the list
void reverseList(LIST *list);                               // reverse the list
void nodeAddedCallback(int value);
void nodeRemovedCallback(int value);


void *myMalloc(size_t size);
void myFree(void *ptr);

#endif