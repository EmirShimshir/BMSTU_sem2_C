#ifndef __SUBSTR_H__

#define __SUBSTR_H__

#include <stdio.h>
#include <string.h>
#include "consts.h"
#include "declarations.h"

void print_product(product_t product);
int check_substr(char *name, char *substr);
int print_substr_products(FILE *f, char *substr);

#endif
