#include <stdio.h>
#include <math.h>

#define EXIT_SUCCESS 0 

int main(void)
{
    double x_a, y_a;
    double x_b, y_b;
    double x_c, y_c;

    printf("Enter x_a, y_a, x_b, y_b, x_c, y_c: ");
    scanf("%lf%lf%lf%lf%lf%lf", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c);

    double first_side = sqrt(pow((x_b - x_a), 2) + pow((y_b - y_a), 2));
    double second_side = sqrt(pow((x_b - x_c), 2) + pow((y_b - y_c), 2));
    double third_side = sqrt(pow((x_a - x_c), 2) + pow((y_a - y_c), 2));

    double p = first_side + second_side + third_side;

    printf("P = %f\n", p);

    return EXIT_SUCCESS;
}
