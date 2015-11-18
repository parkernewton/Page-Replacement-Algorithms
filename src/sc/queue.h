//
//  queue.h
//  PageReplacementAlgorithms
//
//  Created by Parker Newton on 11/4/15.
//  Copyright © 2015 Parker Newton. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>

typedef struct node {
    unsigned long long val;
    unsigned char ref;
    struct node *pNext, *pPrev;
} NODE;

typedef struct queue {
    unsigned long long count;   /* Size of queue. */
    NODE *head;                 /* Sentinel node. */
} QUEUE;

QUEUE* createQueue(unsigned long long n);
/* Takes the size of the queue as a param, and initializes and returns a new queue. */

void destroyQueue(QUEUE *q);
/* Destroys the queue passed as a param. */

void enqueue(QUEUE *q, unsigned long long val, unsigned long long ref);
/* Enqueues a new node onto q with the specified data value and reference bit. */

unsigned long long dequeue(QUEUE *q);
/* Dequeues a node from the queue passed as a param, and returns its data value. */

unsigned char topReferenceBit(QUEUE *q);
/* Tops the queue passed as a param and returns its reference bit. */

unsigned long long queueSize(QUEUE *q);
/* Returns the size of the queue passed as a param. */

unsigned char findNode(QUEUE *q, unsigned long long val);
/* Searches the queue for the specified data value. Returns 1 on success, 0 on error. */

void setReferenceBit(QUEUE *q, unsigned long long val);
/* Sets the reference bit on the node with the specified data value. */

#endif /* queue_h */
