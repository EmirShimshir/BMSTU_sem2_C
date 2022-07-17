#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#define ERROR_INCORRECT_INPUT_N 1
#define ERROR_INCORRECT_INPUT_ARRAY 2
#define ERROR_NO_ELEMENTS 3
#define NUMBER_OF_ARGUMENTS 1
#define EPS 1e-3
#define N 10

int input_array(int *array, size_t n)
{
    printf("Enter elements: ");
    for (size_t i = 0; i < n; i++)
    {
        if (scanf("%d", &array[i]) != NUMBER_OF_ARGUMENTS)
        {
            printf("Error: incorrect input array\n");
            return ERROR_INCORRECT_INPUT_ARRAY;
        }
    }
    return EXIT_SUCCESS;
}

void print_array(int *array, size_t n)
{
    printf("Result: ");
    for (size_t i = 0; i < n; i ++)
        printf("%d ", array[i]);
    printf("\n");
}

int is_full_square(int x)
{
    int odd = 1;

    while (x > 0)
    {
        x -= odd;
        odd += 2;
    }

    return (x == 0);
}

void remove_element(int *array, size_t i, size_t *n)
{
    for (size_t j = i; j < (*n - 1); j++)
    {
        array[j] = array[j + 1];
    }
    (*n)--;
} 

void remove_full_squares(int *array, size_t *n)
{
    for (size_t i = 0; i < *n; i++)
    {
        if (is_full_square(array[i]))
        {
            remove_element(array, i, n);
            i--;
        }
    }
}

int main(void)
{
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

    int array[N];
    int error = input_array(array, n);

    if (error != EXIT_SUCCESS)
        return error;

    remove_full_squares(array, &n);

    if (n == 0)
    {
        printf("Empty array\n");
        return ERROR_NO_ELEMENTS;
    }

    print_array(array, n);
    
    return EXIT_SUCCESS;
}
