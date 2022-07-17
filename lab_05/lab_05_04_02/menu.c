#include "menu.h"

int open_file(FILE **f_in, char *mode, char *argv[])
{
    int error;
    *f_in = fopen(argv[2], mode);
    error = check_is_correct_file(*f_in);
    if (error != EXIT_SUCCESS)
    {
        if (error == ERR_FILE)
        {
            return ERR_FILE;
        }

        if (error == ERR_EMPTY)
        {
            fclose(*f_in);
            return ERR_EMPTY;
        }
    }
    
    return EXIT_SUCCESS;
}

int menu_sort(char *argv[])
{
    int error;
    FILE *f_in = NULL;
    error = open_file(&f_in, "rb", argv);
    if (error != EXIT_SUCCESS)
        return error;

    FILE *f_out = f_out = fopen(argv[3], "wb+");

    copy_file(f_out, f_in);
    sort_file(f_out);

    fclose(f_in);
    fclose(f_out);

    return EXIT_SUCCESS;
}

int menu_print_substr(char *argv[])
{
    int error;
    FILE *f_in = NULL;
    error = open_file(&f_in, "rb", argv);
    if (error != EXIT_SUCCESS)
        return error;

    error = print_substr_products(f_in, argv[3]);
    if (error != EXIT_SUCCESS)
    {
        fclose(f_in);
        return error;
    }

    fclose(f_in);

    return EXIT_SUCCESS;
}

int menu_add_info(char *argv[])
{
    int error;
    FILE *f_in = NULL;
    error = open_file(&f_in, "rb+", argv);
    if (error != EXIT_SUCCESS)
        return error;

    product_t product;
    memset(&product, 0, sizeof(product_t));

    error = entry_struct(&product);
    if (error != EXIT_SUCCESS)
    {
        fclose(f_in);
        return error;
    }

    add_product(f_in, product);

    fclose(f_in);

    return EXIT_SUCCESS;
}
