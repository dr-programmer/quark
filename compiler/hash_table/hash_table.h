#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../structures.h"

typedef struct {
    struct symbol **symbols;
    unsigned long size;
    unsigned long capacity; /* must be a power of two */
} HashTable;

HashTable hash_table_init(unsigned long capacity);

unsigned long hash_function(HashTable *hashTable, const char *name);

void hash_table_insert(HashTable *hashTable, struct symbol *symbol);
struct symbol *hash_table_search(HashTable *hashTable, const char *name);
void hash_table_free(HashTable *hashTable);

#endif