#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include <libgeometry/check.h>
#include <libgeometry/mymath.h>

int main()
{
    char figure[64];
    int n;

    printf("enter the number of shapes:");
    scanf("%d\n", &n);
    if (n == 0 || n < 0) {
        printf("stop!!! you entered 0 or <0!!!");
    } else {
        while (n > 0) {
            fgets(figure, 64, stdin);
            figure[0] = tolower(figure[0]);
            if (circle(figure) == 0) {
                printf("\nperimeter: %f\narea: %f\n", GetCirclePerimeter(figure), GetCircleArea(figure));
            }
            n--;

        }
    }
    return 0;
}