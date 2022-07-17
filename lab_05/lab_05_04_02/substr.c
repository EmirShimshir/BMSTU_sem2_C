#include "substr.h"

void print_product(product_t product)
{
    printf("%s\n", product.name);
    printf("%s\n", product.author);
    printf("%u\n", product.price);
    printf("%u\n", product.count);
}

int check_substr(char *name, char *substr)
{
    int len_name = strlen(name) - 1;
    int len_substr = strlen(substr) - 1;

    while (len_substr >= 0)
    {
        if (name[len_name] != substr[len_substr])
            return FALSE;

        len_substr--;
        len_name--;
    }

    return TRUE;
}

int print_substr_products(FILE *f, char *substr)
{
    size_t size;
    file_size(f, &size);

    int count_substr = 0;
    for (size_t i = 0; i < size; i++)
    {
        product_t product;
        get_product_by_pos(f, i, &product);

        int rc = check_substr(product.name, substr);
        if (rc == TRUE)
        {
            count_substr++;
            print_product(product);
        }
    }

    if (count_substr == 0)
        return ERR_NO_MATCHES;

    return EXIT_SUCCESS;
}
