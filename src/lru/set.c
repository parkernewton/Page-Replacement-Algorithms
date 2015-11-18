//
//  set.c
//  PageReplacementAlgorithms
//
//  Created by Parker Newton on 11/7/15.
//  Copyright © 2015 Parker Newton. All rights reserved.
//

#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

SET* createSet(long long size) {
    SET *s = (SET *)malloc(sizeof(SET));
    assert(s != NULL);
    s->count = 0;
    s->size = size;
    s->elts = (NODE **)malloc(size * sizeof(NODE));
    assert(s->elts != NULL);
    return s;
}

void destroySet(SET *s) {
    assert(s != NULL && s->elts != NULL);
    for(unsigned long long i = 0; i < s->count; i++)
        free(s->elts[i]);
    free(s->elts);
    free(s);
}

void insertElement(SET *s, unsigned long long elt) {
    assert(s != NULL && s->elts != NULL);
    if(s->count < s->size && findElement(s, elt) == -1) {
        NODE *pNew = (NODE *)malloc(sizeof(NODE));
        assert(pNew != NULL);
        pNew->count = 0;
        pNew->val = elt;
        s->elts[s->count++] = pNew;
    }
}

void eraseElement(SET *s, unsigned long long elt) {
    long long index;
    NODE *pDel, *pEnd;
    assert(s != NULL && s->elts != NULL);
    if(s->count && (index = findElement(s, elt)) >= 0) {
        pDel = s->elts[index];
        pEnd = s->elts[--s->count];
        
        pDel->val = pEnd->val;
        pDel->count = pEnd->count;
        
        free(pEnd);
    }
}

long long getSetSize(SET *s) {
    assert(s != NULL && s->elts != NULL);
    return s->count;
}

void setCounterOnElement(SET *s, unsigned long long elt, unsigned long long counter) {
    long long index;
    assert(s != NULL && s->elts != NULL);
    if((index = findElement(s, elt)) >= 0)
        s->elts[index]->count = counter;
}

long long findElement(SET *s, unsigned long long elt) {
    assert(s != NULL && s->elts != NULL);
    for(long long i = 0; i < s->count; i++) {
        if(s->elts[i]->val == elt)
            return i;
    }
    return -1;
}

unsigned long long findMinElement(SET *s) {
    unsigned long long min;
    NODE *pMin;
    assert(s != NULL && s->elts != NULL);
    if(s->count > 0) {
        pMin = s->elts[0];
        for(int i = 1; i < s->count; i++) {
            if(s->elts[i]->count < pMin->count)
                pMin = s->elts[i];
        }
        min = pMin->val;
    }
    return min;
}
