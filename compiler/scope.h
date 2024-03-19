#ifndef SCOPE_H
#define SCOPE_H

#include "structures.h"
#include "stack/stack.h"

void scope_enter();
void scope_exit();
int scope_level();
void scope_bind(struct symbol *symbol);
struct symbol *scope_lookup(const char *name);
struct symbol *scope_lookup_current(const char *name);

#endif