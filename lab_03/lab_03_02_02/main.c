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

int is_sum_digit_odd(int number)
{
    if (number < 0)
        number *= -1;

    int sum = 0;
    while (number > 0)  
    {
        sum += number % 10;
        number /= 10;
    }

    if (sum % 2 == 0)
        return false;

    return true;
}

int is_required_string(int array[], size_t n)
{
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (is_sum_digit_odd(array[i]))
            count++;

        if (count == 2)
            return true;
    }
    
    return false;
}

void add_string(int matrix[][M], size_t *n, size_t m, size_t k)
{
    for (size_t i = *n; i > k; i--)
        for (size_t j = 0; j < m; j++)
            matrix[i][j] = matrix[i - 1][j];
    
    (*n)++;

    for (size_t j = 0; j < m; j++)
        matrix[k][j] = -1;
}

void insert_string(int matrix[][M], size_t *n, size_t m)
{
    for (size_t i = 0; i < *n; i++)
        if (is_required_string(matrix[i], m))
        {
            add_string(matrix, n, m, i);
            i++;
        }
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

int main(void)
{
    int matrix[N][M];
    size_t n;
    size_t m;

    int error = input(matrix, &n, &m);
    if (error != EXIT_SUCCESS)
        return error;

    insert_string(matrix, &n, m);

    print_matrix(matrix, n, m);
    
    return EXIT_SUCCESS;
}
