#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define ERROR_INCORRECT_INPUT_N 1
#define ERROR_INCORRECT_INPUT_ARRAY 2
#define ERROR_NO_ELEMENTS 3
#define NUMBER_OF_ARGUMENTS 1
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
}

int is_begin_end_equal(int x)
{
    x = abs(x);
    int end = x % 10;

    while (x > 10)
    {
        x /= 10;
    }
    int begin = x;

    return begin == end;
}

int same_begin_end_in_new_array(int *new_array, int *array, size_t n, size_t *new_arr_size)
{
    for (size_t i = 0; i < n; i++)
    {
        if (is_begin_end_equal(array[i]))
        {
            new_array[*new_arr_size] = array[i];
            (*new_arr_size)++;
        }
    }
    if (*new_arr_size == 0)
        return ERROR_NO_ELEMENTS;
    return EXIT_SUCCESS;
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
    {
        return error;
    }

    int new_array[N];
    size_t new_arr_size = 0;

    error = same_begin_end_in_new_array(new_array, array, n, &new_arr_size);

    if (error != EXIT_SUCCESS)
        return error;

    print_array(new_array, new_arr_size);
    
    return EXIT_SUCCESS;
}
