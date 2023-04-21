#include <stdio.h>
#include <stdlib.h>
#include "linear_list.h"

struct node {                           //designing node for linked list using structure
    int value;                          //value part of the node
    struct node *next;                  //pointer of node-type containing address of next node
};                                      //address of first node

struct list {
    NODE *head;                  //address of head node
    NODE *tail;                  //address of tail node
};

NODE *createNode(int value) { //
    NODE *newNode = (NODE *)malloc(sizeof(NODE));   //new node (type casting)
    if (!newNode)                    
        return NULL;                                 //out of memory 
                                    
    newNode->value = value;                         //set value
    newNode->next = NULL;                           //create
    return newNode;                                 //return pointer to new node in the list of nodes
}

LIST *createList() { 
    LIST *newList = (LIST *)malloc(sizeof(LIST));
    if (!newList)                       // out of memory              
        return NULL;

    newList->head = NULL;               //create list of nodes with value 0 and length 0 and head is NULL
    newList->tail = NULL;               //create list of nodes with value 0 and length 0 and tail is NULL        
    return newList;                     
}

void printList(LIST *list) {                  
    NODE *temp = list->head;                //  pointer to head node
    while (temp) {                             // loop through nodes and print 
        printf("%d ", temp->value);             
        temp = temp->next;                      
    }
    printf("\n");
}

void addNode(LIST *list, int value) {
    NODE *newNode = createNode(value);
    if (!newNode)           // out of memory 
        return;
        
    if (!list->head) {          
        list->head = newNode;           
        list->tail = newNode;
        return;
    }
    
    NODE *current = list->head;             
    while (current->next)               
        current = current->next;
        
    newNode->next = current->next;
    current->next = newNode;
    list->tail = newNode;
    return;
}

void deleteNode(LIST *list, int value) {
    NODE *current = list->head;
    NODE *prev = NULL;
    while (current) {
        if (current->value == value) {
            if (prev)
                prev->next = current->next;
            else
                list->head = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    return;
}

void deleteList(LIST *list) {
    NODE *current = list->head;
    while (current) {
        NODE *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
    return;
}

void reverseList(LIST *list) {
    NODE *current = list->head;
    NODE *prev = NULL;
    NODE *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
    list->tail = current;
    return;
}
