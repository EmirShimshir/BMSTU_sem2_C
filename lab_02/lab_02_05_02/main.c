#include <stdio.h>
#include <stdlib.h>

#define ERROR_INCORRECT_INPUT_N 1
#define ERROR_INCORRECT_INPUT_ARRAY 2
#define ERROR_NO_ELEMENTS 3
#define NUMBER_OF_ARGUMENTS 1
#define EPS 1e-3
#define N 10

int input_array(int *pb, int *pe)
{
    printf("Enter elements: ");
    int *pcur = pb;
    while (pcur < pe)
    {
        if (scanf("%d", pcur) != NUMBER_OF_ARGUMENTS)
        {
            printf("Error: incorrect input array\n");
            return ERROR_INCORRECT_INPUT_ARRAY;
        }
        pcur++;
    }
    return EXIT_SUCCESS;
}

int *find_neg_ind(int *pb, int *pe)
{
    int *pcur = pb;
    while (pcur < pe)
    {
        if (*pcur < 0)
            return ++pcur;
        pcur++;
    }
    return pcur;
}

int factorial(int *pb, int *pe)
{
    int temp = 1;
    int *pcur = pb;

    while (pcur < pe)
    {
        temp *= *pcur;
        pcur++;
    }

    return temp;
}

int count_sum(int *pb, int *pm)
{
    int s = 0;
    int *pcur = pb;
    while (pcur < pm)
    {
        pcur++;
        s += factorial(pb, pcur);
    }
    return s;
}

#if 0
void print_array(int *pb, int *pe)
{
    printf("Result: ");
    int *pcur = pb;
    while (pcur < pe)
    {
        printf("%d ", *pcur);
        pcur++;
    } 
}
#endif

int main(void)
{
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != NUMBER_OF_ARGUMENTS)
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
    int *pb = array, *pe = array + n;
    int error = input_array(pb, pe);

    if (error != EXIT_SUCCESS)
        return error;

    int *pm = find_neg_ind(pb, pe);
    int sum = count_sum(pb, pm);
    printf("%d", sum);

    return EXIT_SUCCESS;
}
