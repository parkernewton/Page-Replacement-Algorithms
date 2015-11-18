//
//  lru.h
//  PageReplacementAlgorithms
//
//  Created by Parker Newton on 11/7/15.
//  Copyright © 2015 Parker Newton. All rights reserved.
//

#ifndef lru_h
#define lru_h

#include <stdio.h>
#include <stdlib.h>

void initLRU(long long cacheSize);
/* Takes our cache size as a param, and initializes the second chance mechanism. */

void destroyLRU(void);
/* Destroys the second chance mechanism. */

void referencePage(unsigned long long pageId, unsigned long long *numReferences, unsigned long long *numFaults);
/* Queries the second chance mechanism for a page reference.
 *
 * Params:
 *          unsigned long long pageId               The page no. we are requesting.
 *          unsigned long long *numReferences     Counter for current no. of page requests, will increment every call.
 *          unsigned long long *numFaults       Counter for current no. of page faults, will increment if it incurrs a miss.
 */

#endif /* lru_h */
