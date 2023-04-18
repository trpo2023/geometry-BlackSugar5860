#include <libgeometry/mymath.h>
double GetCircleRadius(char* str)
{
    int length = 0;
    char radius[10];
    while (str[length] != ',') {
        length++;
    }

    length++; //шаг через запятую
    int current = 0;
    while (str[length] != ')') {
        radius[current] = str[length];
        current++;
        length++;
    }
    radius[current + 2] = '\0';
    double circleRadius = atof(radius);
    return circleRadius;
}

double GetCirclePerimeter(char str[])
{
    double circleRadius = GetCircleRadius(str);
    double circlePerimeter = M_PI * circleRadius * 2;
    return circlePerimeter;
}

double GetCircleArea(char str[])
{
    double circleRadius = GetCircleRadius(str);
    double circleArea = M_PI * circleRadius * circleRadius;
    return circleArea;
}