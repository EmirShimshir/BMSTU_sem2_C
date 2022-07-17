#ifndef __SORT_FILE_H__

#define __SORT_FILE_H__

#include <stdio.h>
#include <stdlib.h>

#include "consts.h"
#include "file_size.h"

data_t get_number_by_pos(FILE *f, int index);

void put_number_by_pos(FILE *f, int index, data_t number);

int sort_file(char *file_name);

void insert_sort(int count_elems, FILE *f);

#endif
