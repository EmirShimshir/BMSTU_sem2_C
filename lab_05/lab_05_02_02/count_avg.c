#include "count_avg.h"

int count_avg(FILE *f, double *avg)
{
    int count = 0;
    double number;

    while (fscanf(f, "%lf", &number) == COUNT_READ)
    {
        count++;
        *avg += number;
    }

    if (count == 0)
        return ERR_NO_NUMBER;

    *avg /= count;

    return EXIT_SUCCESS;
}
