#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define ERROR_INCORRECT_INPUT_ARRAY 1
#define ERROR_FULL_ARRAY 100
#define NUMBER_OF_ARGUMENTS 1
#define N 10

int input_array(int *array, size_t *n)
{
    for (size_t i = 0; i < N; i++)
    {
        int scanf_output = scanf("%d", &array[i]);

        if ((scanf_output != NUMBER_OF_ARGUMENTS) && (i == 0))
            return ERROR_INCORRECT_INPUT_ARRAY;

        
        if (scanf_output != NUMBER_OF_ARGUMENTS)
            return EXIT_SUCCESS;
            
        (*n)++;
    }
    int test;
    if (scanf("%d", &test) == NUMBER_OF_ARGUMENTS)
        return ERROR_FULL_ARRAY;
    
    return EXIT_SUCCESS;
}

void print_array(int *array, size_t n)
{
    printf("Output array: ");
    for (size_t i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void insertion_sort(int *array, size_t n)
{
    for (size_t i = 1; i < n; i++)
    {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && temp < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

int main(void)
{
    int a[N];
    size_t n = 0;

    printf("Input array: ");
    int error = input_array(a, &n);

    if (error == ERROR_INCORRECT_INPUT_ARRAY)
        return error;

    insertion_sort(a, n);

    print_array(a, n);

    return error;
}
