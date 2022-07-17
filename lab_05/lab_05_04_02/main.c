#include <stdio.h>
#include <string.h>

#include "declarations.h"
#include "consts.h"
#include "sort.h"
#include "substr.h"
#include "add_info.h"
#include "menu.h"

int main(int argc, char *argv[])
{
    int error;
    if ((argc == 4) && (strcmp("sb", argv[1]) == 0))
    {
        error = menu_sort(argv);
        if (error != EXIT_SUCCESS)
            return error;

        return EXIT_SUCCESS;
    }

    if ((argc == 4) && (strcmp(argv[1], "fb") == 0))
    {
        error = menu_print_substr(argv);
        if (error != EXIT_SUCCESS)
            return error;

        return EXIT_SUCCESS;
    }

    if ((argc == 3) && ((strcmp(argv[1], "ab") == 0)))
    {
        error = menu_add_info(argv);
        if (error != EXIT_SUCCESS)
            return error;

        return EXIT_SUCCESS;
    }
    
    return ERR_ARGS;
}
