#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include <libgeometry/check.h>
#include <libgeometry/mymath.h>

int main()
{
    struct FigureInfo* current
            = (struct FigureInfo*)malloc(sizeof(struct FigureInfo));
    current->prev = NULL;
    int n;

    printf("Введите количество фигур: ");
    scanf("%d\n", &n);
    if (n == 0 || n < 0) {
        printf("Стоп!!! Вы ввели число = 0 или < 0");
    } else {
        while (n > 0) {
            current->circle = (char*)malloc(sizeof(struct FigureInfo));
            fgets(current->circle, 64, stdin);
            if (circle(current->circle) == 0) {
                current->next
                        = (struct FigureInfo*)malloc(sizeof(struct FigureInfo));
                printf("\nДанные о фигуре:\n");
                printf("Периметр: %f\nПлощадь: %f\nКоличество пересений: "
                       "%d\n\n",
                       perimeter(current->circle, current),
                       area(current->circle, current),
                       intersections(current->circle, current));
                struct FigureInfo* node = current;
                current = current->next;
                current->prev = node;
            }
            n--;
        }
    }
    return 0;
}