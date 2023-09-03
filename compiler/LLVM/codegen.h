#ifndef CODEGEN_H
#define CODEGEN_H

#include "../structures.h"

unsigned int register_create();
const char *register_name(struct complex_reg sreg);
const char *value_name(struct expr *e);

const char *symbol_irgen(struct symbol *s);

const char *type_irgen(struct type *t);

void type_cast(struct expr *e);
void apply_type_cast(type_t type_kind, 
                            struct complex_reg result_register, 
                            struct type *from_type, 
                            struct complex_reg old_register, 
                            struct type *to_type);

void decl_irgen(struct decl *d);
void stmt_irgen(struct stmt *s, struct symbol *function_symbol);
void expr_irgen(struct expr *e);

#endif