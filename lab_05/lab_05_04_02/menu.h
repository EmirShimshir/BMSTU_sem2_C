#ifndef __MENU_H__

#define __MENU_H__

#include <stdio.h>
#include <string.h>
#include "consts.h"
#include "declarations.h"
#include "add_info.h"
#include "sort.h"
#include "substr.h"

int menu_sort(char *argv[]);
int menu_print_substr(char *argv[]);
int menu_add_info(char *argv[]);
int open_file(FILE **f_in, char *mode, char *argv[]);

#endif
