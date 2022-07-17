#include <stdio.h>

#define EXIT_SUCCESS 0 

int main(void)
{
    int sec;

    printf("Enter sec: ");
    scanf("%d", &sec);

    int hour = sec / 3600;
    int min = (sec % 3600) / 60;
    sec = (sec % 3600) % 60;

    printf("hour = %d\nmin = %d\nsec = %d\n", hour, min, sec);

    return EXIT_SUCCESS;
}
