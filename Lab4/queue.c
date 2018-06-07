/*
 * Adds items to the queue, removes and prints items from the queue
 * Also calculates the size of the queue
 * 
 * File: queue.c
 * Author: Fiona Siu
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Add an item to the rear of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not */
ItemType *enqueue(Queue *queue, ItemType *item) {
    ListNode *thisNode = (ListNode*) malloc(sizeof (ListNode));
    
    if (thisNode == NULL) {
        return NULL;
    }

    thisNode->item = item;
    thisNode->next = NULL;

    if (queue->front == NULL) {
        queue->front = thisNode;
    } else {
        queue->rear->next = thisNode;
    }
    queue->rear = thisNode;
    (*queue).size++;
    return item;
}

/* Removes an item from the front of the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
ItemType *dequeue(Queue *queue) {
    if (queue->front == NULL){
        return NULL;
    }
    
    ListNode *thisNode = queue->front;
    queue->front = queue->front -> next;
    (*queue).size--;
    
    ItemType *item = thisNode->item;
    free(thisNode);
    return item;
}

/* Returns:  number of items in the queue */
int queueSize(const Queue queue) {
    return queue.size;
}

/* Print the contents of the queue to the specified stream */
void printQueue(const Queue queue, FILE *stream) {
    ListNode *thisNode = queue.front;
    
    while (thisNode != NULL) {
        fprintf(stream, "%d\n", *(thisNode->item));
        thisNode = thisNode->next;
    }
}
