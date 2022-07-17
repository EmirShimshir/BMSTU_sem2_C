#include "print_file.h"

int print_file(char *file_name)
{
    FILE *f = fopen(file_name, "rb");
    if (f == NULL)
        return ERR_FILE;

    size_t size;

    int error = file_size(f, &size);
    if (error != EXIT_SUCCESS) 
        return error;

    int count_elems = size / sizeof(data_t);

    if (count_elems == 0)
        return ERR_EMPTY;

    int count_read;
    data_t number;

    for (int i = 0; i < count_elems; i++)
    {
        count_read = fread(&number, sizeof(data_t), 1, f); 

        if (count_read != 1)
            return ERR_READ;

        fprintf(stdout, "%d ", number);
    }

    fclose(f);

    return EXIT_SUCCESS;
}
