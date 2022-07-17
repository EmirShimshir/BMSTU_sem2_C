#include <stdio.h>

#define EXIT_SUCCESS 0 

int main(void)
{
    double r1, r2, r3;

    printf("Enter r1, r2, r3: ");
    scanf("%lf%lf%lf", &r1, &r2, &r3);

    double r = 1 / (1 / r1 + 1 / r2 + 1 / r3);

    printf("r = %f\n", r);

    return EXIT_SUCCESS;
}
