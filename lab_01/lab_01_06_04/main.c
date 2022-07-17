#include <stdio.h>
#include <math.h>

#define EPS 1e-3
#define NUMBER_OF_ARGUMENTS 6
#define EXIT_SUCCESS 0
#define ERROR_INCORRECT_INPUT 1
#define ERROR_SAME_POINTS 2

/**
 * @brief This function checks if a point lies inside a segment in section
 * @param x coordinate of checking point 
 * @param y coordinate of checking point
 * @param x_1 coordinate 1 point
 * @param y_1 coordinate 1 point
 * @param x_2 coordinate 2 point
 * @param y_2 coordinate 2 point
 * @return 0 - no, 1 - yes
 */

int is_in_section(double x, double y, double x_1, double y_1, double x_2, double y_2)
{
    double s_x1_x2 = sqrt((x_2 - x_1) * (x_2 - x_1) + (y_2 - y_1) * (y_2 - y_1));
    double s_x1_x = sqrt((x - x_1) * (x - x_1) + (y - y_1) * (y - y_1));
    double s_x2_x = sqrt((x - x_2) * (x - x_2) + (y - y_2) * (y - y_2));

    return (fabs((s_x1_x + s_x2_x) - s_x1_x2) < EPS);
}

int main(void)
{
    double x_1, y_1, x_2, y_2, x, y;

    printf("Enter x_1, y_1, x_2, y_2, x, y: ");

    if (scanf("%lf%lf%lf%lf%lf%lf", &x_1, &y_1, &x_2, &y_2, &x, &y) != NUMBER_OF_ARGUMENTS)
    {
        printf("Incorrect input\n");
        return ERROR_INCORRECT_INPUT;
    }

    if ((fabs(x_1 - x_2) < EPS) && (fabs(y_1 - y_2) < EPS))
    {
        printf("It's the same points\n");
        return ERROR_SAME_POINTS;
    }

    int status = is_in_section(x, y, x_1, y_1, x_2, y_2);

    printf("%d\n", status);

    return EXIT_SUCCESS;
}
