/*
Сортировка "типизированного" бинарного файла (int)
методом простого выбора по возрастанию
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "create_file.h"
#include "print_file.h"
#include "sort_file.h"
#include "consts.h"

int main(int argc, char *argv[])
{
    if (argc != 3) 
        return ERR_ARGS;

    int error;
    int count_elems = atoi(argv[1]);
    if (count_elems > 0)
    {
        error = create_file(argv[2], count_elems);
        if (error != EXIT_SUCCESS)
            return error;
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        error = print_file(argv[2]);
        if (error != EXIT_SUCCESS)
            return error;
    }
    else if (strcmp(argv[1], "s") == 0)
    {
        error = sort_file(argv[2]);
        if (error != EXIT_SUCCESS)
            return error;
    }
    else 
    {
        return ERR_ARGS;
    }

    return EXIT_SUCCESS;
}
