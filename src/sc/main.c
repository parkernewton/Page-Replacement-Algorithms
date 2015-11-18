//
//  main.c
//  PageReplacementAlgorithms
//
//  Created by Parker Newton on 11/4/15.
//  Copyright © 2015 Parker Newton. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "parser.h"
#include "secondChance.h"

int main(int argc, const char * argv[]) {
    char buf[100];
    unsigned long long numRequests = 0, numFaults = 0, cacheSize;
    long long pageId;
    
    /* Read the cache size as a program param. */
    assert(argc == 2);
    sscanf(argv[1], "%llu", &cacheSize);
    
    initSecondChance(cacheSize);
    
    /* While we read a valid page no., make a page reference. */
    while((pageId = getNextPageNumber(buf, 100, stdin)) >= 0)
        requestPage((unsigned long long)pageId, &numRequests, &numFaults);
    
    tearDownSecondChance();
    
    /* Print our global page references and faults counters. */
    printf("\nNumber of page requests: %llu \nNumber of page faults: %llu \n", numRequests, numFaults);
    
    return EXIT_SUCCESS;
}
