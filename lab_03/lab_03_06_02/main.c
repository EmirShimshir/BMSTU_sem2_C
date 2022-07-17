#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define ERROR_INCORRECT_INPUT_PARAM 1  

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

void fill_matrix(int matrix[][M], size_t n, size_t m)
{
    printf("Enter elements:\n");
    int number = 1;
    for (size_t j = 0; j < m; j++)
        for (size_t i = 0; i < n; i++)
        {
            size_t index_j = m - 1 - j;
            size_t index_i;

            if (j % 2 == 0)
                index_i = n - 1 - i;
            else 
                index_i = i;

            matrix[index_i][index_j] = number;
            number++;
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

    printf("Enter n: ");
    int error = input_matrix_param(&n);
    if (error != EXIT_SUCCESS)
        return error;

    printf("Enter m: ");
    error = input_matrix_param(&m);
    if (error != EXIT_SUCCESS)
        return error;

    fill_matrix(matrix, n, m);
    print_matrix(matrix, n, m);
    
    return EXIT_SUCCESS;
}
