#include "create_file.h"

int create_file(char *file_name, int count_elems)
{
    FILE *f = fopen(file_name, "wb");
    if (f == NULL)
        return ERR_FILE;

    data_t number;
    int count_wrote;

    for (int i = 0; i < count_elems; i++)
    {
        number = rand() % 10;
        count_wrote = fwrite(&number, sizeof(data_t), 1, f);
        if (count_wrote != 1)
        {
            fclose(f);
            return ERR_WRITE;
        }
    }

    fclose(f);

    return EXIT_SUCCESS;
}
