#include <stdio.h>

#include "scope.h"

#define HASH_TABLE_INIT_CAPACITY 128

Stack symbol_table;

void scope_enter() {
    HashTable temp = hash_table_init(HASH_TABLE_INIT_CAPACITY);
    pushStack(&symbol_table, temp);
}
void scope_exit() {
    popStack(&symbol_table);
}
int scope_level() {
    return lenStack(&symbol_table);
}
void scope_bind(struct symbol *symbol) {
    hash_table_insert(&symbol_table.list.head->value, symbol);
}
struct symbol *scope_lookup(const char *name) {
    struct ListNode *current = symbol_table.list.head;
    while(current != NULL) {
        struct symbol *temp = hash_table_search(&current->value, name);
        if(temp)return temp;
        current = current->next;
    }
    return NULL;
}
struct symbol *scope_lookup_current(const char *name) {
    return hash_table_search(&symbol_table.list.head->value, name);
}