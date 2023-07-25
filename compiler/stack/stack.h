#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"

typedef struct {
    LinkedList list;
} Stack;

void pushStack(Stack *stack, HashTable value);
HashTable popStack(Stack *stack);
int lenStack(Stack *stack);
void printlist(LinkedList *list);

#endif