//
//  parser.c
//  PageReplacementAlgorithms
//
//  Created by Parker Newton on 11/4/15.
//  Copyright © 2015 Parker Newton. All rights reserved.
//

#include "parser.h"

#define END_OF_FILE -1
#define INVALID_INPUT -1

long long validateInput(char *in);
/* Validates 'in' as a page no.
 * Returns a non-negative page no. on success, or -1 on error. 
 */

long long getNextPageNumber(char *buf, int bufSize, FILE *istream) {
    long long pageNo = INVALID_INPUT;
    do {
        if(fgets(buf, bufSize, istream) == NULL)
            return END_OF_FILE;
    } while((pageNo = validateInput(buf)) == INVALID_INPUT);
    return pageNo;
}

long long validateInput(char *in) {
    long long pageNo;
    if(sscanf(in, "%lld", &pageNo))
        return pageNo; 
    return INVALID_INPUT;
}
