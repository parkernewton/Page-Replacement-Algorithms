//
//  clock.c
//  
//
//  Created by Parker Newton on 11/8/15.
//
//

#include "clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h" 

typedef struct clock {
    unsigned long long numPages;    /* The size of our cache. */
    QUEUE *pages;                   /* Pointer to our queue of pages. */
} CLOCK;

static CLOCK *clk;
static FILE *fp;

void printPageFault(unsigned long long pageId);
/* Prints to the stdout the page no. that incurrs a miss. */

void initClock(unsigned long long cacheSize) {
    assert((clk = (CLOCK *)malloc(sizeof(CLOCK))) != NULL);
    clk->numPages = cacheSize;
    clk->pages = createQueue(cacheSize);
    assert((fp = fopen("out.txt", "w")) != NULL);
}

void destroyClock(void) {
    fclose(fp);
    destroyQueue(clk->pages);
    free(clk);
}

void referencePage(unsigned long long pageId, unsigned long long *numReferences, unsigned long long *numFaults) {
    /* ----------------------------
     * CLOCK ALGORITHM
     * ----------------------------
     * If we find the requested page in our cache, then set its reference bit to 1. Finished.
     * Else, we must select a page to evict.
     * If our queue size is not full, then simply enqueue the requested page.
     * Otherwise, top our queue and examine the reference bit.
     * While it is 1, dequeue the page, set its ref bit to 0, and then enqueue it.
     * Once we have found a page with a ref bit of 0, dequeue it.
     * Then, we enqueue our requested page. Finished.
     */
    if(!findNode(clk->pages, pageId)) {
        if(!isQueueFull(clk->pages)) {
            enqueue(clk->pages, pageId, 1);
        }
        else {
            while(topReferenceBit(clk->pages))
                enqueue(clk->pages, dequeue(clk->pages), 0);
            
            dequeue(clk->pages);
            enqueue(clk->pages, pageId, 1);
        }
        (*numFaults)++;
        printPageFault(pageId);
    }
    else {
        setReferenceBit(clk->pages, pageId);
    }
    (*numReferences)++;
}

void printPageFault(unsigned long long pageId) {
    assert(fprintf(fp, "%llu \n", pageId) >= 0);
}
