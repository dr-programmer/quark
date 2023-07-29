#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

HashTable hash_table_init(unsigned long capacity) {
    HashTable h = {.symbols = NULL, .size = 0, .capacity = capacity};
    h.symbols = (struct symbol **)calloc(h.capacity, sizeof(struct symbol *));
    return h;
}

static void hash_table_resize(HashTable *hashTable, unsigned long newSize) {
    if(newSize >= (hashTable->capacity/2)) {
        hashTable->capacity *= 2;
        hashTable->symbols = (struct symbol **)
            realloc(hashTable->symbols, hashTable->capacity * sizeof(struct symbol *));
    }
    hashTable->size = newSize;
}
/* Implementing a djb2 algorithm with a minor change: 
            the return index is within the range of our hash table
            because of this expression: hash & (hashTable->capacity-1) */
unsigned long hash_function(HashTable *hashTable, const char *name) {
    unsigned long hash = 5381;
    int c;

    while (c = *name++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash & (hashTable->capacity-1);
}

void hash_table_insert(HashTable *hashTable, struct symbol *symbol) {
    unsigned long newSize = hashTable->size+1;
    hash_table_resize(hashTable, newSize);
    unsigned long index = hash_function(hashTable, symbol->name);
    for(;; index++) {
        if(index >= hashTable->capacity)index = 0;
        if(hashTable->symbols[index] == NULL)break;
    }
    hashTable->symbols[index] = symbol;
}
struct symbol *hash_table_search(HashTable *hashTable, const char *name) {
    unsigned long index = hash_function(hashTable, name);
    for(; hashTable->symbols[index] != NULL; index++) {
        if(!strcmp(name, hashTable->symbols[index]->name)) {
            //printf("Name = %s \n", hashTable->symbols[index]->name);
            return hashTable->symbols[index];
        }
        if(index >= hashTable->capacity)index = 0;
    }
    return NULL;
}
void hash_table_free(HashTable *hashTable) {
    free(hashTable->symbols);
}
/*
int main()
{
    HashTable table = hash_table_init(128);
    struct symbol symbol = {SYMBOL_LOCAL, NULL, "depravement", 0};
    struct symbol symbol1 = {SYMBOL_LOCAL, NULL, "serafins", 0};
    struct symbol symbol2 = {SYMBOL_LOCAL, NULL, "something", 0};
    struct symbol symbol3 = {SYMBOL_LOCAL, NULL, "asd", 0};
    struct symbol symbol4 = {SYMBOL_LOCAL, NULL, "qwe", 0};
    struct symbol symbol5 = {SYMBOL_LOCAL, NULL, "123", 0};
    struct symbol symbol6 = {SYMBOL_LOCAL, NULL, "567", 0};
    struct symbol *test = NULL;
    struct symbol *test1 = NULL;
    struct symbol *test2 = NULL;
    struct symbol *test3 = NULL;
    struct symbol *test4 = NULL;
    struct symbol *test5 = NULL;
    struct symbol *test6 = NULL;

    hash_table_insert(&table, &symbol);
    hash_table_insert(&table, &symbol1);
    hash_table_insert(&table, &symbol2);
    hash_table_insert(&table, &symbol3);
    hash_table_insert(&table, &symbol4);
    hash_table_insert(&table, &symbol5);
    hash_table_insert(&table, &symbol6);
    test = hash_table_search(&table, "depravement");
    test1 = hash_table_search(&table, "serafins");
    test2 = hash_table_search(&table, "something");
    test3 = hash_table_search(&table, "asd");
    test4 = hash_table_search(&table, "qwe");
    test5 = hash_table_search(&table, "123");
    test6 = hash_table_search(&table, "567");

    hash_table_free(&table);

    return 0;
}
*/