//
//  LinkedList.c
//  AlgoAvancee
//
//  Created by Robert Mogos on 4/7/16.
//  Copyright © 2016 Eventually. All rights reserved.
//

#include "LinkedList.h"
#include <stdlib.h>

LinkedList *newLinkedList() {
  LinkedList *list = malloc(sizeof(LinkedList));
  list->size = 0;
  return list;
}

Node *newNode(int value) {
  Node *node = malloc(sizeof(Node));
  node->value = value;
  return node;
}