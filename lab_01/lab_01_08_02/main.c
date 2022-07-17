#include <stdio.h>
#include <stdint.h>

#define EXIT_SUCCESS 0
#define ERROR_INCORRECT_INPUT 1
#define ERROR_NEGATIVE_N 2
#define NUMBER_OF_ARGUMENTS 2

/**
 * @brief This function makes cyclic shift
 * @param a number 
 * @param n left shift number 
 * @return uint32_t a - new nunber
 */

uint32_t cyclic_shift(uint32_t a, int n)
{
    uint32_t mask;
    
    for (int i = 0; i < n; i++)
    {
        mask = (a >> 31) & 1;
        a <<= 1;
        a |= mask;
    }

    return a;
}

/**
 * @brief This function prints number in binary
 * @param a number 
 * @return void (print number in binary)
 */

void bin_print(uint32_t a)
{
    uint32_t first_bit = 0x00000001;

    printf("Result: ");

    for (int i = 31; i >= 0; i--)
        printf("%u", (a >> i) & first_bit);
    printf("\n");
}

int main(void)
{
    uint32_t a;
    int n;
    
    printf("Enter a, n: ");

    if (scanf("%u%d", &a, &n) != NUMBER_OF_ARGUMENTS)
    {
        printf("Error: incorrect input\n");
        return ERROR_INCORRECT_INPUT;
    }

    if (n < 0)
    {
        printf("Error: negative n\n");
        return ERROR_NEGATIVE_N;
    }

    a = cyclic_shift(a, n);
    bin_print(a);

    return EXIT_SUCCESS;
}
