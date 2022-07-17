#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define ERROR_INCORRECT_INPUT_PARAM 1
#define ERROR_INCORRECT_INPUT_MATRIX 2

#define NUMBER_OF_ARGUMENTS 1
#define N 10
#define M 10

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

int input_matrix(int matrix[][M], size_t n, size_t m)
{
    printf("Enter elements:\n");
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            if (scanf("%d", &matrix[i][j]) != NUMBER_OF_ARGUMENTS)
            {
                printf("Error: incorrect input matrix\n");
                return ERROR_INCORRECT_INPUT_MATRIX;
            }
        }

    return EXIT_SUCCESS;
}

int input(int matrix[][M], size_t *n, size_t *m)
{
    printf("Enter n: ");
    int error = input_matrix_param(n);
    if (error != EXIT_SUCCESS)
        return error;

    printf("Enter m: ");
    error = input_matrix_param(m);
    if (error != EXIT_SUCCESS)
        return error;

    error = input_matrix(matrix, *n, *m);
    if (error != EXIT_SUCCESS)
        return error;

    return EXIT_SUCCESS;
}

void print_matrix(int matrix[][M], size_t n, size_t m)
{
    printf("Print matrix:\n");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

int count_product(int array[], size_t n)
{
    int product = 1;
    for (size_t i = 0; i < n; i++)
        product *= array[i];

    return product;
}

void swap_strings(int matrix[][M], size_t m, size_t a, size_t b)
{
    for (size_t j = 0; j < m; j++)
    {
        int temp = matrix[a][j];
        matrix[a][j] = matrix[b][j];
        matrix[b][j] = temp;
    }
}

void sort_strings(int matrix[][M], size_t n, size_t m)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        size_t min_string = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (count_product(matrix[j], m) < count_product(matrix[min_string], m))
                min_string = j;
        }

        if (min_string != i)
            swap_strings(matrix, m, i, min_string);
    }
}

int main(void)
{
    int matrix[N][M];
    size_t n;
    size_t m;

    int error = input(matrix, &n, &m);
    if (error != EXIT_SUCCESS)
        return error;

    sort_strings(matrix, n, m);

    print_matrix(matrix, n, m);
    
    return EXIT_SUCCESS;
}
