#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // Get start and end size from the user, if any of them is invalid it will ask again

    int startSize;

    do
    {
        printf("Enter start size: ");
        scanf("%d", &startSize);
    }
    while (startSize < 9);

    int endSize;

    do
    {
        printf("Enter end size: ");
        scanf("%d", &endSize);
    }
    while (endSize < startSize);

    int years = 0;
    int population = startSize;

    // Calculate and print the amount of years

    while (population < endSize)
    {
        int newLlamas = population / 3;
        int llamasPassedAway = population / 4;
        population += newLlamas - llamasPassedAway;
        years++;
    }

    printf("Years: %d\n", years);

    return 0;
}