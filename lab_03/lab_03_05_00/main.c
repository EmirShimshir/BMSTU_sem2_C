#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#define ERROR_INCORRECT_INPUT_PARAM 1
#define ERROR_INCORRECT_INPUT_MATRIX 2
#define ERROR_NO_PRIME 3

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

int is_prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) 
            return false;
    return true;
}

int collect_prime(int matrix[][M], size_t n, size_t m, int array_prime[], size_t *size_arr)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (is_prime(matrix[i][j]))
            {
                array_prime[*size_arr] = matrix[i][j];
                (*size_arr)++;
            }

    if (*size_arr == 0)
    {
        printf("Error: no prime elements\n");
        return ERROR_NO_PRIME;
    }

    return EXIT_SUCCESS;
}

void reverse_array(int array[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = array[i];
        array[i] = array[n - 1 - i];
        array[n - 1 - i] = temp;
    }
}

void fill_matrix(int matrix[][M], size_t n, size_t m, int array_prime[])
{
    int index = 0;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (is_prime(matrix[i][j]))
            {
                matrix[i][j] = array_prime[index];
                index++;
            }
        }   
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

    int array_prime[N * M];
    size_t size_arr = 0;

    error = collect_prime(matrix, n, m, array_prime, &size_arr);
    if (error != EXIT_SUCCESS)
        return error;

    reverse_array(array_prime, size_arr);

    fill_matrix(matrix, n, m, array_prime);

    print_matrix(matrix, n, m);
    
    return EXIT_SUCCESS;
}
