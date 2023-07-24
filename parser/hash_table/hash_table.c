#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"

HashTable hash_table_init(unsigned long capacity) {
    HashTable h = {.symbols = NULL, .size = 0, .capacity = capacity};
    h.symbols = (struct symbol **)malloc(h.capacity * sizeof(struct symbol *));
    return h;
}

static void hash_table_resize(HashTable *hashTable, unsigned long newSize) {
    if(newSize >= (hashTable->capacity*0.8)) {
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
    if(hashTable->symbols[index] != NULL) {
        printf("Collision");
        /* collision resolution */
    }
    else hashTable->symbols[index] = symbol;
}
struct symbol *hash_table_search(HashTable *hashTable, const char *name) {
    unsigned long index = hash_function(hashTable, name);
    if(hashTable->symbols[index] != NULL) {
        printf("Name = %s \n", hashTable->symbols[index]->name);
        return hashTable->symbols[index];
    }
    else return NULL;
}
void hash_table_free(HashTable *hashTable) {
    free(hashTable->symbols);
}

int main()
{
    HashTable table = hash_table_init(128);
    struct symbol symbol = {SYMBOL_LOCAL, NULL, "testing", 0};
    struct symbol symbol1 = {SYMBOL_LOCAL, NULL, "var", 0};
    struct symbol symbol2 = {SYMBOL_LOCAL, NULL, "something", 0};
    struct symbol *test = NULL;
    struct symbol *test1 = NULL;
    struct symbol *test2 = NULL;

    hash_table_insert(&table, &symbol);
    hash_table_insert(&table, &symbol1);
    hash_table_insert(&table, &symbol2);
    test = hash_table_search(&table, "testing");
    test1 = hash_table_search(&table, "var");
    test2 = hash_table_search(&table, "something");

    hash_table_free(&table);

    return 0;
}