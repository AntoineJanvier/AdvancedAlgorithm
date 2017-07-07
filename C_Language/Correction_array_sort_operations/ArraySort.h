//
//  ArraySort.h
//  AlgoAvancee
//
//  Created by Robert Mogos on 3/16/16.
//  Copyright © 2016 Eventually. All rights reserved.
//

#ifndef ArraySort_h
#define ArraySort_h

#include "IntArray.h"

/**
 Returns a sorted array. 
 Worst and average runtime complexity: O(n^2)
 Space complexity: O(1)
 **/
void array_bubble_sort(IntArray *array);


/**
 Returns a sorted array
 Average runtime complexity: O(nlogn)
 Worst runtime complexity: O(n^2)
 Space complexity: O(1)
 **/
void array_quick_sort(IntArray *array);
void array_quick_sort_boundries(IntArray *array, int start, int end);

void array_bucket_sort(IntArray * array);
#endif /* ArraySort_h */
