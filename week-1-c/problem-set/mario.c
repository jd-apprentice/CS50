#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    // Ask the user about the height

    int height;

    bool condition;

    do {
        printf("Enter height: ");
        scanf("%d", &height);

        condition = height >= 1 && height <= 8;

    } while (!condition);

    // We build the asset!

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }

        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}