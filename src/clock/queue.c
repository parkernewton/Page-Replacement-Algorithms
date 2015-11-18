//
//  queue.c
//  
//
//  Created by Parker Newton on 11/8/15.
//
//

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

QUEUE* createQueue(unsigned long long size) {
    QUEUE *q = (QUEUE *)malloc(sizeof(QUEUE));
    assert(q != NULL);
    q->size = size;
    q->count = 0;
    q->pHead = 0;
    q->elts = (NODE **)malloc(size * sizeof(NODE *));
    assert(q->elts != NULL);
    return q;
}

void destroyQueue(QUEUE *q) {
    assert(q != NULL && q->elts != NULL);
    for(unsigned long long i = 0; i < q->count; i++)
        free(q->elts[i]);
    free(q->elts);
    free(q);
}

void enqueue(QUEUE *q, unsigned long long val, unsigned char ref) {
    assert(q != NULL && q->elts != NULL);
    if(!isQueueFull(q)) {
        NODE *pNew = (NODE *)malloc(sizeof(NODE));
        assert(pNew != NULL);
        pNew->val = val;
        pNew->ref = ref;
        q->elts[(q->pHead + q->count++) % q->size] = pNew;
    }
}

unsigned long long dequeue(QUEUE *q) {
    unsigned long long val = 0;
    assert(q != NULL && q->elts != NULL);
    if(!isQueueEmpty(q)) {
        val = q->elts[q->pHead]->val;
        q->elts[q->pHead] = NULL;
        q->pHead = (q->pHead + 1) % q->size;
        q->count--;
    }
    return val;
}

unsigned char topReferenceBit(QUEUE *q) {
    assert(q != NULL && q->elts != NULL);
    return !isQueueEmpty(q) ? q->elts[q->pHead]->ref : 0;
}

unsigned char isQueueFull(QUEUE *q) {
    assert(q != NULL && q->elts != NULL);
    return q->count == q->size;
}

unsigned char isQueueEmpty(QUEUE *q) {
    assert(q != NULL && q->elts != NULL);
    return q->count == 0;
}

unsigned char findNode(QUEUE *q, unsigned long long val) {
    assert(q != NULL && q->elts != NULL);
    for(unsigned long long i = 0; i < q->count; i++) {
        if(q->elts[i]->val == val)
            return 1;
    }
    return 0;
}

void setReferenceBit(QUEUE *q, unsigned long long val) {
    assert(q != NULL && q->elts != NULL);
    for(unsigned long long i = 0; i < q->count; i++) {
        if(q->elts[i]->val == val)
            q->elts[i]->ref = 1;
    }
}
