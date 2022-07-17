#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#define ERROR_INCORRECT_INPUT_PARAM 1
#define ERROR_INCORRECT_INPUT_MATRIX 2
#define ERROR_NO_NUMBERS 3
#define ERROR_NOT_SQUARE 4

#define NUMBER_OF_ARGUMENTS 1
#define N 10

int input_matrix_param(size_t *x)
{
    int rc = scanf("%zu", x);
    if ((rc != NUMBER_OF_ARGUMENTS) || (*x <= 0) || (*x > 10))
    {
        printf("Error: incorrect input\n");
        return ERROR_INCORRECT_INPUT_PARAM;
    }

    return EXIT_SUCCESS;
}

int input_matrix(int matrix[][N], size_t n)
{
    printf("Enter elements:\n");
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
        {
            if (scanf("%d", &matrix[i][j]) != NUMBER_OF_ARGUMENTS)
            {
                printf("Error: incorrect input matrix\n");
                return ERROR_INCORRECT_INPUT_MATRIX;
            }
        }

    return EXIT_SUCCESS;
}

int input(int matrix[][N], size_t *n, size_t *m)
{
    printf("Enter n: ");
    int error = input_matrix_param(n);
    if (error != EXIT_SUCCESS)
        return error;

    printf("Enter m: ");
    error = input_matrix_param(m);
    if (error != EXIT_SUCCESS)
        return error;

    if (*n != *m)
    {
        printf("Error: not square matix\n");
        return ERROR_NOT_SQUARE;
    }

    error = input_matrix(matrix, *n);
    if (error != EXIT_SUCCESS)
        return error;

    return EXIT_SUCCESS;
}

int find_max_under_side(int matrix[][N], size_t n, int *max)
{
    int has_number = false;

    for (size_t i = 1; i < n; i++)
        for (size_t j = n - i; j < n; j++)
        {
            int element = matrix[i][j];
            if (abs(element) % 10 == 5 && (!has_number || *max < element))
            {
                has_number = true;
                *max = element;
            }
        }

    if (has_number == false)
    {
        printf("Error: no numbers ends with five\n");
        return ERROR_NO_NUMBERS;
    }

    return EXIT_SUCCESS;    
}

int main(void)
{
    int matrix[N][N];
    size_t n;
    size_t m;

    int error = input(matrix, &n, &m);
    if (error != EXIT_SUCCESS)
        return error;

    int max_number;

    error = find_max_under_side(matrix, n, &max_number);
    if (error != EXIT_SUCCESS)
        return error;

    printf("Max number: %d\n", max_number);
    
    return EXIT_SUCCESS;
}
