//
//  Stack.c
//  AlgoAvancee
//
//  Created by Robert Mogos on 6/23/16.
//  Copyright © 2016 Eventually. All rights reserved.
//

#include "Stack.h"
#include <stdlib.h>

Stack *newStack() {
  Stack *stack = malloc(sizeof(Stack));
  stack->size = 0;
  return stack;
}