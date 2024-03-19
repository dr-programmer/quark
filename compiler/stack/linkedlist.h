#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../hash_table/hash_table.h"

struct ListNode {
    HashTable value;
    struct ListNode *next;
};

typedef struct {
    int size;
    struct ListNode *head;
} LinkedList;

LinkedList init();

struct ListNode *get(LinkedList *list, int index);

void push(LinkedList *list, int index, HashTable value);
void pushback(LinkedList *list, HashTable value);
void pushfront(LinkedList *list, HashTable value);

HashTable pop(LinkedList *list, int index);
HashTable popfront(LinkedList *list);
HashTable popback(LinkedList *list);

void set(LinkedList *list, int index, HashTable value);

void release(LinkedList *list);

#endif