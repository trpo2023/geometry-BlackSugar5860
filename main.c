#include <stdio.h>
#include <string.h>
#include <ctype.h>

void circle(char figure[])
{
    char str[6] = "circle";

    for (int i = 0; i < 5; i++)
    {
        figure[i] = tolower(figure[i]);
        if (figure[i] != str[i])
        {
            char strerr[6];
            strncpy(strerr, figure, 6);
            strerr[6] = "\0";
            printf("Error at column 0: expected 'circle' instead of %s\n", strerr);
            return;
        }
    }

    int k = 7;

    char str2[13] = "-.0123456789";
    if (figure[6] != '(')
    {
        printf("Error at column %d: expected '('\n", k);
        return;
    }
    while (figure[k] == ' ')
    {
        k++;
    }
    if (figure[k] == '0')
    {
        if (figure[k + 1] != '.' && strchr(str2, figure[k + 1]) != NULL)
        {
            printf("Error at column %d: expected '.'\n", k);
            return;
        }
    }

    if (figure[k] == ',' || figure[k] == ')')
    {
        printf("Error at column %d: expected number\n", k);
        return;
    }

    if (strchr(str2, figure[k]) == NULL)
    {
        printf("Error at column %d: unexpected character\n", k);
        return;
    }

    while (strchr(str2, figure[k]) != NULL)
    {
        k++;
    }

    if (figure[k] == ',' || figure[k] == ')')
    {
        printf("Error at column %d: expected number\n", k);
        return;
    }

    if (figure[k] != ' ')
    {
        printf("Error at column %d: expected ' \n", k);
        return;
    }

    while (figure[k] == ' ')
    {
        k++;
    }

    if (figure[k + 1] == '0')
    {
        if (figure[k + 2] != '.')
        {
            printf("Error at column %d: expected '.'\n", k + 1);
            return;
        }
    }

    if (strchr(str2, figure[k]) == NULL)
    {
        printf("Error at column %d: unexpected character\n", k);
        return;
    }

    while (strchr(str2, figure[k]) != NULL)
    {
        k++;
    }

    if (figure[k] != ' ' && figure[k] != ',')
    {
        printf("Error at column %d: expected ','\n", k);
    }

    while (figure[k] == ' ')
    {
        k++;
    }

    if (figure[k] != ',')
    {
        printf("Error at column %d: expected ','\n", k);
        return;
    }
    else
    {
        k++;
    }
    while (figure[k] == ' ')
    {
        k++;
    }
    if (figure[k] == '0')
    {
        if (figure[k + 1] != '.')
        {
            printf("Error at column %d: expected '.'\n", k);
            return;
        }
    }

    if (figure[k] == ',' || figure[k] == ')')
    {
        printf("Error at column %d: expected number\n", k);
        return;
    }

    if (strchr(str2, figure[k]) == NULL)
    {
        printf("Error at column %d: unexpected character\n", k);
        return;
    }

    while (strchr(str2, figure[k]) != NULL)
    {
        k++;
    }

    if (figure[k] != ')')
    {
        printf("Error at column %d: expected ')'\n", k);
    }
    else
    {
        printf("succeed\n");
    }
}

int main()
{
    char figure1[64];
    char figure2[64];

    fgets(figure1, 63, stdin);
    fgets(figure2, 63, stdin);

    switch (figure1[0])
    {
    case 'c':
        circle(figure1);
        break;
    case 't':
        // triangle(figure1);
        break;
    case 'p':
        // polygon(figure1);
        break;
    default:
        printf("Error at column 0: expected 'Circle', 'Triangle' or 'Polygon'\n");
    }
        switch (figure2[0])
    {
    case 'c':
        circle(figure2);
        break;
    case 't':
        // triangle(figure1);
        break;
    case 'p':
        // polygon(figure1);
        break;
    default:
        printf("Error at column 0: expected 'Circle', 'Triangle' or 'Polygon'\n");
    }
    return 0;
}