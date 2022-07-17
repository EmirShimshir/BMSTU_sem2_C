#include "add_info.h"

int entry_struct(product_t *product)
{
    int rc;
    printf("Enter name: ");
    rc = scanf("%s", product->name);
    printf("Enter manufactorer: ");
    rc += scanf("%s", product->author);
    printf("Enter price: ");
    rc += scanf("%u", &(product->price));
    printf("Enter count: ");
    rc += scanf("%u", &(product->count));

    return (rc == 4) ? EXIT_SUCCESS : ERR_READ;
}

void add_product(FILE *f, product_t product)
{
    size_t size;
    file_size(f, &size);

    int pos = 0;
    product_t product_temp;
    memset(&product_temp, 0, sizeof(product_t));

    for (size_t i = 0; i < size; i++)
    {
        get_product_by_pos(f, pos, &product_temp);

        if ((product.price > product_temp.price) || (product.price == product_temp.price && product.count > product_temp.count))
            break;
        pos++;
    }

    for (int i = size - 1; i >= pos; i--)
    {
        get_product_by_pos(f, i, &product_temp);
        put_product_by_pos(f, i + 1, product_temp);
    }

    put_product_by_pos(f, pos, product);
}
