#include "../structures.h"

unsigned int register_create();
const char *register_name(int r);

const char *symbol_irgen(struct symbol *s);

const char *type_irgen(struct type *t);

void type_cast(struct expr *e);

unsigned int callr_create();
const char *callr_name(int r);

void decl_irgen(struct decl *d);
void stmt_irgen(struct stmt *s, struct symbol *function_symbol);
void expr_irgen(struct expr *e);