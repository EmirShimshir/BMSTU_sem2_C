#ifndef __DECLARATIONS_H__

#define __DECLARATIONS_H__

#include "consts.h"

typedef struct
{
    char name[MAX_NAME_SIZE];
    char author[MAX_AUTHOR_SIZE];
    unsigned int price;
    unsigned int count;
} product_t;

void get_product_by_pos(FILE *f, size_t pos, product_t *product);
void put_product_by_pos(FILE *f, size_t pos, product_t product);
void file_size(FILE *f, size_t *size);
int check_is_correct_file(FILE *f);

#endif
