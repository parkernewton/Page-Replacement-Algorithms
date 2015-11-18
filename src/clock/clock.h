//
//  clock.h
//  
//
//  Created by Parker Newton on 11/8/15.
//
//

#ifndef clock_h
#define clock_h

#include <stdio.h>

void initClock(unsigned long long cacheSize);
/* Takes our cache size as a param, and initializes the clock mechanism. */

void destroyClock(void);
/* Destroys the clock mechanism. */

void referencePage(unsigned long long pageId, unsigned long long *numReferences, unsigned long long *numFaults);
/* Queries the clock mechanism for a page reference.
 *
 * Params:
 *          unsigned long long pageId               The page no. we are requesting.
 *          unsigned long long *numReferences       Counter for current no. of page requests, will increment every call.
 *          unsigned long long *numFaults           Counter for current no. of page faults, will increment if it incurrs a miss.
 */

#endif /* clock_h */
