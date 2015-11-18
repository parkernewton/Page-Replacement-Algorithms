//
//  secondChance.c
//  PageReplacementAlgorithms
//
//  Created by Parker Newton on 11/5/15.
//  Copyright © 2015 Parker Newton. All rights reserved.
//

#include "secondChance.h"
#include <assert.h>

typedef struct secondChange {
    QUEUE *pages;                   /* Ptr to our queue of pages. */
    unsigned long long numPages;    /* Size of our cache. */
    
} SECOND_CHANCE;

static SECOND_CHANCE *sc;
static FILE *fp;

void printPageFault(unsigned long long pageId);
/* Prints to the stdout the page fault incurred by requesting 'pageId'. */

void initSecondChance(unsigned long long cacheSize) {
    sc = (SECOND_CHANCE *)malloc(sizeof(SECOND_CHANCE));
    assert(sc != NULL);
    sc->pages = createQueue(cacheSize);
    sc->numPages = cacheSize;
    fp = fopen("out.txt", "w");
    assert(fp != NULL);
}

void requestPage(unsigned long long pageId, unsigned long long *numPageRequests, unsigned long long *numPageFaults) {
    /* ------------------------
     * SECOND CHANCE ALGORITHM
     * ------------------------
     * If we find the requested page in our cache, then set its reference bit to 1. Finished. 
     * Else, we must select a page to evict. 
     * If our queue size is not full, then simply enqueue the requested page.
     * Otherwise, top our queue and examine the reference bit. 
     * While it is 1, dequeue the page, set its ref bit to 0, and then enqueue it. 
     * Once we have found a page with a ref bit of 0, dequeue it. 
     * Then, we enqueue our requested page. Finished.
     */
    if(!findNode(sc->pages, pageId)) {
        if(queueSize(sc->pages) < sc->numPages) {
            enqueue(sc->pages, pageId, 1);
        }
        else {
            while(topReferenceBit(sc->pages))
                enqueue(sc->pages, dequeue(sc->pages), 0);
            
            dequeue(sc->pages);
            enqueue(sc->pages, pageId, 1);
        }
        (*numPageFaults)++;
        printPageFault(pageId);
    }
    else {
        setReferenceBit(sc->pages, pageId);
    }
    (*numPageRequests)++;
}

void printPageFault(unsigned long long pageId) {
    assert(fprintf(fp, "%llu \n", pageId) >= 0);
}

void tearDownSecondChance(void) {
    fclose(fp);
    destroyQueue(sc->pages);
    free(sc); 
}
