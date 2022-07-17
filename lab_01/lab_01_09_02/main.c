#include <stdio.h>
#include <math.h>

#define EXIT_SUCCESS 0
#define ERROR_INCORRECT_INPUT 1
#define ERROR_INCORRECT_SERIES 2
#define NUMBER_OF_ARGUMENTS 1

/**
 * @brief This function computes series
 * @param *error error status
 * @return result series value
 */

int compute_series(double *result)
{
    double x;

    if (scanf("%lf", &x) != NUMBER_OF_ARGUMENTS)
        return ERROR_INCORRECT_INPUT;

    if (x < 0)
        return ERROR_INCORRECT_SERIES;

    double g = 0;
    int n = 0;

    do
    {
        n++;
        g += sqrt(n + x);

        if (scanf("%lf", &x) != NUMBER_OF_ARGUMENTS)
            return ERROR_INCORRECT_INPUT;
    }
    while (x >= 0);

    *result = g / n;
    return EXIT_SUCCESS;
}

int main(void)
{
    double result;
    
    printf("Enter x's: ");
    int error = compute_series(&result);

    if (error == ERROR_INCORRECT_INPUT)
    {
        printf("Error: incorrect input\n");
        return ERROR_INCORRECT_INPUT;
    }

    if (error == ERROR_INCORRECT_SERIES)
    {
        printf("Error: incorrect series\n");
        return ERROR_INCORRECT_SERIES;
    }

    printf("Result: %lf\n", result);
    return EXIT_SUCCESS;
}
