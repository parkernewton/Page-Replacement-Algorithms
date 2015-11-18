//
//  lfu.c
//  PageReplacementAlgorithms
//
//  Created by Parker Newton on 11/7/15.
//  Copyright © 2015 Parker Newton. All rights reserved.
//

#include "lfu.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "set.h"

typedef struct lfu {
    unsigned long long numPages;
    SET *pages;
} LFU;

static LFU *lfu;
static FILE *fp;

void printPageFault(unsigned long long pageId);
/* Prints to the stdout the page fault incurred by requesting 'pageId'. */

void initLFU(unsigned long long cacheSize) {
    assert((lfu = (LFU *)malloc(sizeof(LFU))) != NULL);
    lfu->numPages = cacheSize;
    lfu->pages = createSet(cacheSize);
    assert((fp = fopen("out.txt", "w")) != NULL);
}

void destroyLFU(void) {
    fclose(fp);
    destroySet(lfu->pages);
    free(lfu);
}

void referencePage(unsigned long long pageId, unsigned long long *numReferences, unsigned long long *numFaults) {
    /* --------------------------------
     * LEAST FREQUENTLY USED ALGORITHM 
     * --------------------------------
     * If we find the requested page in our cache, then increment its frequency counter and set its timestamp to our global counter value. Finished.
     * Else, we must select a page to evict. 
     * If our cache is not full, then simply insert the page. 
     * Otherwise, find the page with the lowest frequency counter value (ties are broken by lowest timestamp (LRU)), and replace it with our requested page. 
     * Then, increment the frequency counter on our new page and set its timestamp to our global counter value. Finished.
     */
    (*numReferences)++;
    if(findElement(lfu->pages, pageId) < 0) {
        if(isSetFull(lfu->pages))
            eraseElement(lfu->pages, findMinElement(lfu->pages));
        insertElement(lfu->pages, pageId);
        (*numFaults)++;
        printPageFault(pageId);
    }
    incrementCounterOnElement(lfu->pages, pageId, *numReferences);
}

void printPageFault(unsigned long long pageId) {
    assert(fprintf(fp, "%llu \n", pageId) >= 0);
}
