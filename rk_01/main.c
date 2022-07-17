//set tabstop=4
//set shiftwidth=4
//set expandtab


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>

#define N 10

void left_shift(int array[], size_t *n);
void right_shift(int array[], size_t *n);


void input_array(int array[], size_t *n)
{
    printf("Input n: ");
    scanf("%zu", n);

    printf("Input array: ");
    for (size_t i = 0; i < *n; i++)
    {
        scanf("%d", &array[i]);
    }
}

void print_array(int array[], size_t n)
{
    printf("Print array:\n");
    for (size_t i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}


void do_operations(int *array_num, size_t *n_num, int *array_oper, size_t n_oper)
{
    for (size_t i = 0; i < n_oper; i++)
    {
        if (array_oper[i] == 1)
            right_shift(array_num, n_num); 
        else
            left_shift(array_num, n_num);
    }
}


void del_i_in_arr(int array[], size_t k, size_t *n)
{
    for (size_t i = k; i < *n - 1; i++)
        array[i] = array[i + 1];
    (*n)--;

}

void right_shift(int array[], size_t *n)
{
    int value = array[0];
    int count = 1;

    for (size_t i = 1; i < *n; i++)
    {
        if (value == array[i])
        {
            count++;
        }
        else
        {
            if (count >= 2)
            {
                array[i - 2] *= 2;
                del_i_in_arr(array, i - 1, n);
                i--;
            }
            value = array[i];
            count = 1;
        }
    }

   if (count >= 2)
   {
        array[*n - 2] *= 2;
        del_i_in_arr(array, *n - 1, n);
   }
 
}

void left_shift(int array[], size_t *n)
{
    int value = array[0];
    int count = 1;

    for (size_t i = 1; i < *n; i++)
    {
        if (value == array[i])
        {
            count++;
        }
        else
        {
            if (count >= 2)
            {
                array[i - count] *= 2;
                del_i_in_arr(array, i - 1, n);
                i--;
            }
            value = array[i];
            count = 1;
        }
    }

    if (count >= 2)
    {
        array[*n - count] *= 2;
        del_i_in_arr(array, *n - 1, n);
    }

}

int main(void)
{
    size_t n_num;
    int array_num[N];
    
    size_t n_oper;
    int array_oper[N];

    input_array(array_num, &n_num);
    input_array(array_oper, &n_oper);

    do_operations(array_num, &n_num, array_oper, n_oper);

    print_array(array_num, n_num);
   // print_array(array_oper, n_oper);

    return 0;	        
}
