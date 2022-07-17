#include "sort.h"

void copy_file(FILE *f_out, FILE *f_in)
{
    size_t size_in;
    file_size(f_in, &size_in);

    product_t product;

    for (size_t i = 0; i < size_in; i++)
    {
        get_product_by_pos(f_in, i, &product);
        fwrite(&product, sizeof(product_t), 1, f_out);
    }
}

void get_product_by_pos(FILE *f, size_t pos, product_t *product)
{
    pos *= sizeof(product_t);
    fseek(f, pos, SEEK_SET);
    fread(product, sizeof(product_t), 1, f);
}

void put_product_by_pos(FILE *f, size_t pos, product_t product)
{
    pos *= sizeof(product_t);
    fseek(f, pos, SEEK_SET);
    fwrite(&product, sizeof(product_t), 1, f);
}

void sort_file(FILE *f)
{
    size_t size;
    file_size(f, &size);

    product_t p_max_pos, p_j;

    for (size_t i = 0; i < size - 1; i++)
    {
        size_t max_pos = i;
        for (size_t j = i + 1; j < size; j++)
        {
            get_product_by_pos(f, max_pos, &p_max_pos); 
            get_product_by_pos(f, j, &p_j);

            if ((p_max_pos.price < p_j.price) || (p_max_pos.price == p_j.price && p_max_pos.count < p_j.count))
            {
                max_pos = j;
            } 
        }
        if (max_pos != i)
        {
            product_t temp;
            get_product_by_pos(f, i, &temp);
            get_product_by_pos(f, max_pos, &p_max_pos); 
            put_product_by_pos(f, i, p_max_pos);
            put_product_by_pos(f, max_pos, temp);
        }
    }
}

void file_size(FILE *f, size_t *size)
{
    fseek(f, 0, SEEK_END);
       
    *size = ftell(f);

    *size /= sizeof(product_t);
}

int check_is_correct_file(FILE *f)
{
    if (f == NULL)
        return ERR_FILE;

    size_t size;
    file_size(f, &size);
    
    if (size == 0)
        return ERR_EMPTY;

    fseek(f, 0, SEEK_SET);

    return EXIT_SUCCESS;
}
