#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

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
    {
        for (size_t j = 0; j < m; j++)
        {
            if (scanf("%d", &matrix[i][j]) != NUMBER_OF_ARGUMENTS)
            {
                printf("Error: incorrect input matrix\n");
                return ERROR_INCORRECT_INPUT_MATRIX;
            }
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

void find_alternating_columns(int matrix[][M], size_t n, size_t m, int array[])
{
    for (size_t j = 0; j < m; j++)
    {
        if (n == 1)
        {
            array[j] = 0;
            continue;
        }

        int alternate = true;
        for (size_t i = 0; i < n - 1; i++)
        {
            if (matrix[i][j] * matrix[i + 1][j] >= 0)
            {
                alternate = false;
                array[j] = 0;
                break;
            }
        }

        if (alternate)
            array[j] = 1;
    }
}

void print_array(int array[], size_t n)
{
    printf("Print array:\n");
    for (size_t i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

#if 0
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
#endif

int main(void)
{
    int matrix[N][M];
    size_t n;
    size_t m;

    int error = input(matrix, &n, &m);
    if (error != EXIT_SUCCESS)
        return error;

    int array[N];

    find_alternating_columns(matrix, n, m, array);

    print_array(array, m);
    
    return EXIT_SUCCESS;
}
