#include "sort_file.h"

data_t get_number_by_pos(FILE *f, int index)
{
    long pos = index * sizeof(data_t);
    data_t number;

    fseek(f, pos, SEEK_SET);
    fread(&number, sizeof(data_t), 1, f);

    return number;
}

void put_number_by_pos(FILE *f, int index, data_t number)
{
    long pos = index * sizeof(data_t);

    fseek(f, pos, SEEK_SET);
    fwrite(&number, sizeof(data_t), 1, f);
}

void insert_sort(int count_elems, FILE *f)
{
    for (int i = 0; i < count_elems - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < count_elems; j++)
        {
            if (get_number_by_pos(f, j) < get_number_by_pos(f, min_pos))
            {
                min_pos = j;
            }
        }
        if (min_pos != i)
        {
            data_t temp = get_number_by_pos(f, i);
            put_number_by_pos(f, i, get_number_by_pos(f, min_pos));
            put_number_by_pos(f, min_pos, temp);
        }
    }
}

int sort_file(char *file_name)
{
    FILE *f = fopen(file_name, "rb+");
    if (f == NULL)
        return ERR_FILE;

    size_t size;

    int error = file_size(f, &size);
    if (error != EXIT_SUCCESS)
        return error;

    int count_elems = size / sizeof(data_t);

    if (count_elems == 0)
        return ERR_EMPTY;

    insert_sort(count_elems, f);

    fclose(f);

    return EXIT_SUCCESS;
}
