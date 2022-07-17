#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EXIT_SUCCESS 0
#define ERROR_INCORRECT_INPUT 1
#define ERROR_INCORRECT_EPS 2
#define ERROR_INCORRECT_X 3
#define NUMBER_OF_ARGUMENTS 2

/**
 * @brief This function uses the taylor formula
 * @param x argument
 * @param eps error
 * @return s - summ
 */

double taylor_formula(double x, double eps)
{
    double s = 0, element = 2;
    int i = 1;

    while (fabs(element / 2) >= eps)
    {
        s += element / 2;
        element *= (-1) * (i + 2) * x / i;
        i++;
    }
    
    return s;
}

int main(void)
{
    double x, eps;

    printf("Enter x, eps: ");

    if (scanf("%lf%lf", &x, &eps) != NUMBER_OF_ARGUMENTS)
    {
        printf("Incorrect input\n");
        return ERROR_INCORRECT_INPUT;
    }

    if (eps <= 0 || eps > 1)
    {
        printf("Incorrect eps\n");
        return ERROR_INCORRECT_EPS;
    }

    if (fabs(x) > 1)
    {
        printf("Incorrect x\n");
        return ERROR_INCORRECT_X;
    } 

    double f = 1 / pow((1 + x), 3);
    double s = taylor_formula(x, eps);

    double abs_error = fabs(f - s);
    double rel_error = abs_error / fabs(f);

    printf("%f %f %f %f", s, f, abs_error, rel_error);

    return EXIT_SUCCESS;
}
