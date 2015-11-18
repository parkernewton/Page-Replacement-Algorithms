//
//  lru.c
//  PageReplacementAlgorithms
//
//  Created by Parker Newton on 11/7/15.
//  Copyright © 2015 Parker Newton. All rights reserved.
//

#include "lru.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include "set.h"

typedef struct lru {
    long long numPages;
    SET *pages;
} LRU;

static LRU *lru;
static FILE *fp;

void printPageFault(unsigned long long pageId);

void initLRU(long long cacheSize) {
    assert((lru = (LRU *)malloc(sizeof(LRU))) != NULL);
    lru->numPages = cacheSize;
    lru->pages = createSet(cacheSize);
    assert((fp = fopen("out.txt", "w")) != NULL);
}

void destroyLRU(void) {
    fclose(fp);
    destroySet(lru->pages);
    free(lru);
}

void referencePage(unsigned long long pageId, unsigned long long *numReferences, unsigned long long *numFaults) {
    /* --------------------------------
     * LEAST RECENTLY USED ALGORITHM:
     * -------------------------------
     * If we find the requested page in our cache, then set its counter to our global counter value. Finished.
     * Else, if our cache is full, then erase the element with the lowest counter.
     * Then, insert the requested page and set its counter to our global counter value. Finished.
     */
    (*numReferences)++;
    if(findElement(lru->pages, pageId) >= 0) {
        setCounterOnElement(lru->pages, pageId, *numReferences); 
    }
    else {
        if(getSetSize(lru->pages) == lru->numPages)
            eraseElement(lru->pages, findMinElement(lru->pages));
        
        insertElement(lru->pages, pageId);
        setCounterOnElement(lru->pages, pageId, *numReferences);
        
        (*numFaults)++;
        printPageFault(pageId);
    }
}

void printPageFault(unsigned long long pageId) {
    assert(fprintf(fp, "%llu \n", pageId) >= 0);
}
