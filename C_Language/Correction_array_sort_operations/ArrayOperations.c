//
//  ArrayOperations.c
//  AlgoAvancee
//
//  Created by Robert Mogos on 3/16/16.
//  Copyright © 2016 Eventually. All rights reserved.
//

#include "ArrayOperations.h"
#include <stdio.h>
#include "IntArray.h"

int array_insert(IntArray *array, int value) {
  if (array->count == array->size) {
    return -1;
  }
  array->values[array->count] = value;
  array->count += 1;
  return 0;
}

int array_insert_at_position(IntArray *array, int value, int postion) {
  if (postion > array->count) {
    return -1;
  }
  if (postion == array->count) {
    return array_insert(array, value);
  }
  array_shift_right(array, postion);
  array->values[postion] = value;
  array->count = array->size == array->count ? array->size : array->count + 1;
  return 0;
}

void array_shift_right(IntArray *array, int start) {
  if (array->size <= start) {
    return;
  }
  int previousElement = array->values[start];
  int i = 0;
  for (i = start + 1; i <= array->count && i < array->size; i++) {
    int tmp = array->values[i];
    array->values[i] = previousElement;
    previousElement = tmp;
  }
}


int array_remove_first_occurence(IntArray *array, int value) {
  int position = array_find(array, value);
  if (position == -1) {
    return -1;
  }
  array_remove_at_position(array, position);
  return position;
}

int array_find(IntArray *array, int value) {
  int i = 0;
  int position = -1;
  for (i = 0; i < array->count; i++) {
    if (array->values[i] == value) {
      position = i;
      break;
    }
  }
  return position;
}

int array_remove_at_position(IntArray *array, int position) {
  if (position >= array->size || 0 == array->count) {
    return -1;
  }
  array_shift_left(array, position);
  array->count -= 1;
  return 0;
}

void array_shift_left(IntArray *array, int start) {
  if (array->size <= start) {
    return;
  }
  int i = 0;
  for (i = start; i < array->size - 1; i++) {
    array->values[i] = array->values[i+1];
  }
}


int array_remove_all_occurences(IntArray *array, int value) {
  int occurances = 0;
  int position = 0;
  for (int i = 0; i < array->count; i++) {
    if (array->values[i] != value) {
      array->values[position] = array->values[i];
      position++;
    } else {
      occurances ++;
    }
  }
  
  array->count -= occurances;
  return occurances;
}

int array_find_binary_search(IntArray *array, int value) {
  return array_find_binary_search_with_boundries(array, value, 0, array->count - 1);
}

int array_find_binary_search_with_boundries(IntArray *array, int value, int start, int end) {
  if (start > end) {
    return -1;
  }
  int mid = (start + end) / 2;
  if (array->values[mid] == value) {
    return mid;
  } else if (array->values[mid] > value) {
    return array_find_binary_search_with_boundries(array, value, start, mid - 1);
  } else {
    return array_find_binary_search_with_boundries(array, value, mid + 1, end);
  }
}

int array_find_binary_search_iteratif(IntArray *array, int value) {
  int start = 0;
  int end = array->count - 1;
  
  while(1) {
    if (start > end) {
      return -1;
    }
    int mid = (start + end) / 2;
    if (array->values[mid] == value) {
      return mid;
    } else if (array->values[mid] > value) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return - 1;
}


void array_swap(IntArray *array, int idx1, int idx2) {
  int tmp = array->values[idx1];
  array->values[idx1] = array->values[idx2];
  array->values[idx2] = tmp;
}


IntArray * array_sorted_merge(IntArray *array1, IntArray *array2) {
  IntArray *array = newArray(array1->count + array2->count);
  int idx1 = 0;
  int idx2 = 0;
  while (idx1 < array1->count && idx2 < array2->count) {
    if (array1->values[idx1] < array2->values[idx2]) {
      array_insert(array, array1->values[idx1]);
      idx1++;
    } else {
      array_insert(array, array2->values[idx2]);
      idx2++;
    }
  }
  for (int i = idx1; i < array1->count; i++) {
    array_insert(array, array1->values[idx1]);
  }
  for (int i = idx2; i < array2->count; i++) {
    array_insert(array, array2->values[idx2]);
  }
  return array;
}

void array_print(IntArray *array) {
  for (int i = 0; i < array->count; i++) {
    printf("%d ", array->values[i]);
  }
  printf("\n");
}
