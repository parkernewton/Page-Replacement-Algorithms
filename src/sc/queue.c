//
//  queue.c
//  PageReplacementAlgorithms
//
//  Created by Parker Newton on 11/4/15.
//  Copyright © 2015 Parker Newton. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>
#include <assert.h>

QUEUE* createQueue(unsigned long long n) {
    QUEUE *q = (QUEUE *)malloc(sizeof(QUEUE));
    assert(q != NULL);
    q->count = 0;
    q->head = (NODE *)malloc(sizeof(NODE));
    assert(q->head != NULL);
    q->head->pNext = q->head->pPrev = q->head;
    return q;
}

void destroyQueue(QUEUE *q) {
    NODE *pCur;
    assert(q != NULL && q->head != NULL);
    pCur = q->head->pNext;
    while(pCur != q->head) {
        pCur = pCur->pNext;
        free(pCur->pPrev);
    }
    free(q->head);
    free(q);
}

void enqueue(QUEUE *q, unsigned long long val, unsigned long long ref) {
    assert(q != NULL && q->head != NULL);
    NODE *pNew = (NODE *)malloc(sizeof(NODE));
    assert(pNew != NULL);
    pNew->val = val;
    pNew->ref = ref;
    q->head->pPrev->pNext = pNew;
    pNew->pPrev = q->head->pPrev;
    pNew->pNext = q->head;
    q->head->pPrev = pNew;
    q->count++;
}

unsigned long long dequeue(QUEUE *q) {
    unsigned long long val = 0;
    NODE *pDel;
    assert(q != NULL && q->head != NULL);
    if(q->count > 0) {
        pDel = q->head->pNext;
        val = pDel->val;
        pDel->pNext->pPrev = q->head;
        q->head->pNext = pDel->pNext;
        free(pDel);
        q->count--;
    }
    return val;
}

unsigned char topReferenceBit(QUEUE *q) {
    assert(q != NULL && q->head != NULL);
    return q->count > 0 ? q->head->pNext->ref : 0;
}

unsigned long long queueSize(QUEUE *q) {
    assert(q != NULL);
    return q->count;
}

unsigned char findNode(QUEUE *q, unsigned long long val) {
    NODE *pCur;
    assert(q != NULL && q->head != NULL);
    pCur = q->head;
    while((pCur = pCur->pNext) != q->head) {
        if(pCur->val == val) 
            return 1;
    }
    return 0;
}

void setReferenceBit(QUEUE *q, unsigned long long val) {
    NODE *pCur;
    assert(q != NULL && q->head != NULL);
    pCur = q->head;
    while((pCur = pCur->pNext) != q->head) {
        if(pCur->val == val)
            pCur->ref = 1;
    }
}
