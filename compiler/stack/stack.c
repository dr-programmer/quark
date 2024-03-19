#include <stdio.h>

#include "stack.h"

Stack initStack() {
    Stack stack;
    stack.list = init();
    return stack;
}

void pushStack(Stack *stack, HashTable value) {
    pushfront(&stack->list, value);
}

HashTable popStack(Stack *stack) {
    return popfront(&stack->list);
}

int lenStack(Stack *stack) {
    return stack->list.size;
}

void printlist(LinkedList *list) {
    struct ListNode *current = list->head;
    while (current != NULL){
        printf("%lu ", current->value.capacity);
        current = current->next;
    }
    printf("\n");
}
/*
int main()
{
    Stack stack = initStack();
    HashTable test1 = hash_table_init(128);
    HashTable test2 = hash_table_init(256);
    HashTable test3 = hash_table_init(512);
    pushStack(&stack, test1);
    printlist(&stack.list);
    pushStack(&stack, test2);
    printlist(&stack.list);
    pushStack(&stack, test3);
    printlist(&stack.list);

    popStack(&stack);
    printlist(&stack.list);
    popStack(&stack);
    printlist(&stack.list);
    popStack(&stack);
    printlist(&stack.list);

    return 0;
}
*/