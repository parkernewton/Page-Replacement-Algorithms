//
//  secondChance.h
//  PageReplacementAlgorithms
//
//  Created by Parker Newton on 11/5/15.
//  Copyright © 2015 Parker Newton. All rights reserved.
//

#ifndef secondChance_h
#define secondChance_h

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initSecondChance(unsigned long long cacheSize);
/* Takes our cache size as a param, and initializes the second chance mechanism. */

void tearDownSecondChance(void);
/* Destroys the second chance mechanism. */

void requestPage(unsigned long long pageId, unsigned long long *numPageRequests, unsigned long long *numPageFaults);
/* Query the second chance mechanism for a page reference.
 *
 * Params: 
 *          unsigned long long pageId               The page no. we are requesting.
 *          unsigned long long *numPageRequests     Counter for current no. of page requests, will increment every call.
 *          unsigned long long *numPageFaults       Counter for current no. of page faults, will increment if it incurrs a miss.
 */

#endif /* secondChance_h */
