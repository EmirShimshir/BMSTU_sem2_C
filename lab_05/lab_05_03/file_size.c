#include "file_size.h"

int file_size(FILE *f, size_t *size)
{
    if (fseek(f, 0L, SEEK_END) != 0)
        return ERR_READ;

    long get_size = ftell(f);
    if (get_size < 0)
        return ERR_READ;

    *size = get_size;

    if (fseek(f, 0L, SEEK_SET) != 0)
        return ERR_READ;

    return EXIT_SUCCESS;
}
