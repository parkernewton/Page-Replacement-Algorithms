//
//  queue.h
//  
//
//  Created by Parker Newton on 11/8/15.
//
//

#ifndef queue_h
#define queue_h

#include <stdio.h>

typedef struct node {
    unsigned long long val;
    unsigned char ref;
} NODE;

typedef struct queue {
    unsigned long long size, count;     /* Size is max capacity. Count is current size. */
    NODE* *elts;                        /* Pointer to array of NODE pointers. */
    unsigned long long pHead;           /* Data value corresponding to the head of the queue. */
} QUEUE;

QUEUE* createQueue(unsigned long long size);
/* Takes the size of the queue as a param, and initializes and returns a new queue. */

void destroyQueue(QUEUE *q);
/* Destroys the queue passed as a param. */

void enqueue(QUEUE *q, unsigned long long val, unsigned char ref);
/* Enqueues a new node onto q with the specified data value and reference bit. */

unsigned long long dequeue(QUEUE *q);
/* Dequeues a node from the queue passed as a param, and returns its data value. */

unsigned char topReferenceBit(QUEUE *q);
/* Tops the queue passed as a param and returns its reference bit. */

unsigned char isQueueFull(QUEUE *q);
/* If the queue is full, returns 1. Else returns 0. */

unsigned char isQueueEmpty(QUEUE *q);
/* If the queue is empty, returns 1. Else returns 0. */

unsigned char findNode(QUEUE *q, unsigned long long val);
/* Searches the queue for the specified data value. Returns 1 on success, 0 on error. */

void setReferenceBit(QUEUE *q, unsigned long long val);
/* Sets the reference bit on the node with the specified data value. */

#endif /* queue_h */
