#include "count_disp.h"

int count_disp(FILE *f, double avg, double *disp)
{
    int count = 0;
    double number;

    while (fscanf(f, "%lf", &number) == COUNT_READ)
    {
        count++;
        *disp += (number - avg) * (number - avg);
    }

    if (count == 0)
        return ERR_NO_NUMBER;
    
    if (count == 1)
        return ERR_ONE_NUMBER;

    *disp /= count;

    return EXIT_SUCCESS;
}
