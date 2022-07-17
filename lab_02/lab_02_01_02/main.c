#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define ERROR_INCORRECT_INPUT_N 1
#define ERROR_INCORRECT_INPUT_ARRAY 2
#define ERROR_NO_NEGATIVE 3
#define NUMBER_OF_ARGUMENTS 1
#define N 10

int input_array(int *a, size_t n)
{
    printf("Enter elements: ");
    for (size_t i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) != NUMBER_OF_ARGUMENTS)
        {
            printf("Error: incorrect input array\n");
            return ERROR_INCORRECT_INPUT_ARRAY;
        }
    }
    return EXIT_SUCCESS;
}

int find_average_of_neg(int *a, size_t n)
{
    double average_neg = 0;
    int count_neg = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            average_neg += a[i];
            count_neg++;
        }
    }

    if (count_neg == 0)
    {
        printf("Error: there are no negative numbers\n");
        return ERROR_NO_NEGATIVE;
    }

    average_neg /= count_neg;
    printf("%lf", average_neg);

    return EXIT_SUCCESS;
}

int main(void)
{
    int a[N];
    size_t n;

    printf("Enter number of elements: ");
    if (scanf("%zu", &n) != NUMBER_OF_ARGUMENTS)
    {
        printf("Error: incorrect input n\n");
        return ERROR_INCORRECT_INPUT_N;
    }

    if ((n <= 0) || (n > 10))
    {
        printf("Error: incorrect number of elements");
        return ERROR_INCORRECT_INPUT_N;
    }

    int error = input_array(a, n);

    if (error != EXIT_SUCCESS)
    {
        return error;
    }

    error = find_average_of_neg(a, n);

    if (error != EXIT_SUCCESS)
        return error;
    
    return EXIT_SUCCESS;
}
