//
//  parser.h
//  PageReplacementAlgorithms
//
//  Created by Parker Newton on 11/4/15.
//  Copyright © 2015 Parker Newton. All rights reserved.
//

#ifndef parser_h
#define parser_h

#include <stdio.h>

long long getNextPageNumber(char *buf, int bufSize, FILE *istream);
/* Gets the next page no. from the input stream. 
 *
 * Params: 
 *          char* buf       A storage location for the next page no.
 *          int bufSize     The size of the buffer. 
 *          FILE *istream   The input stream from which we will read the next page no.
 *
 * Return:  A non-negative value of the next page no. on success, or a negative value on error.
 */

#endif /* parser_h */
