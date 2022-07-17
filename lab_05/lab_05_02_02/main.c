#include <stdio.h>

#include "count_avg.h"
#include "count_disp.h"
#include "consts.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return ERR_ARGS;

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        return ERR_FILE;

    int error;
    double avg = 0;
    error = count_avg(f, &avg);
    if (error != EXIT_SUCCESS)
        return error;

    rewind(f);

    double disp = 0;
    error = count_disp(f, avg, &disp);
    if (error != EXIT_SUCCESS)
        return error;

    fclose(f);

    fprintf(stdout, "%lf\n", disp);

    return EXIT_SUCCESS;
}
