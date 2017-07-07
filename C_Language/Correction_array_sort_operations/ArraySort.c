//
//  ArraySort.c
//  AlgoAvancee
//
//  Created by Robert Mogos on 3/16/16.
//  Copyright © 2016 Eventually. All rights reserved.
//

#include "ArraySort.h"
#include "ArrayOperations.h"
#include <stdlib.h>

void array_bubble_sort(IntArray *array) {
  for (int i = array->count - 1; i > 0; i--) {
    short sorted = 1;
    for (int j = 0; j < i; j++) {
      if (array->values[j] > array->values[j + 1]) {
        array_swap(array, j, j+1);
        sorted = 0;
      }
    }
    if (1 == sorted) {
      break;
    }
  }
}

void array_quick_sort(IntArray *array) {
  array_quick_sort_boundries(array, 0, array->count - 1);
}

void array_quick_sort_boundries(IntArray *array, int start, int end) {
  if (start >= end) {
    return;
  }
  int left = start - 1;
  int right = end + 1;
  int mid = (start + end) / 2;
  int pivot = array->values[mid];
  
  while (left < right) {
    do {
      left += 1;
    } while (array->values[left] < pivot);
    
    do {
      right -= 1;
    } while (array->values[right] > pivot);
    
    if (left < right) {
      array_swap(array, left, right);
    }
  }
  mid = right;
  
  array_quick_sort_boundries(array, start, mid);
  array_quick_sort_boundries(array, mid + 1, end);
}

void array_bucket_sort(IntArray * array) {
  int *tOccurance = malloc(sizeof(int) * 256);
  for (int i = 0; i < 256; i++) {
    tOccurance[i] = 0;
  }
  
  for (int i = 0; i < array->count; i++) {
    tOccurance[array->values[i]] += 1;
  }
  
  int position = 0;
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < tOccurance[i]; j++) {
      array->values[position] = i;
      position ++;
    }
  }
}
