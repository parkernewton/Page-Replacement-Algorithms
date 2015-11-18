//
//  set.h
//  PageReplacementAlgorithms
//
//  Created by Parker Newton on 11/7/15.
//  Copyright © 2015 Parker Newton. All rights reserved.
//

#ifndef set_h
#define set_h

#include <stdio.h>

typedef struct node {
    unsigned long long val, count;
} NODE;

typedef struct set {
    long long size, count;
    NODE* *elts;
} SET;

SET* createSet(long long size);
/* Initializes a new set with the specified max size. */

void destroySet(SET *s);
/* Deallocates the specified set. */

void insertElement(SET *s, unsigned long long elt);
/* Inserts 'elt' into the set 's'. */

void eraseElement(SET *s, unsigned long long elt);
/* Removes and deallocates 'elt' from 's'. */

long long getSetSize(SET *s);
/* Returns the current size of the set 's'. */

void setCounterOnElement(SET *s, unsigned long long elt, unsigned long long counter);
/* Sets the counter on 'elt' to the value 'counter'. */

long long findElement(SET *s, unsigned long long elt);
/* Finds 'elt' in 's'. 
 * On success, returns a non-negative value. 
 * On error, returns a negative value. */

unsigned long long findMinElement(SET *s);
/* Finds the element in 's' with the lowest counter value. */

#endif /* set_h */
