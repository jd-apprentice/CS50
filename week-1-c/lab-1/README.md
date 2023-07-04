# Week 1 - C

## Lab 

Say we have a population of n llamas. Each year, n / 3 new llamas are born, and n / 4 llamas pass away.

For example, if we were to start with n = 1200 llamas, then in the first year, 1200 / 3 = 400 new llamas would be born and 1200 / 4 = 300 llamas would pass away. At the end of that year, we would have 1200 + 400 - 300 = 1300 llamas.

To try another example, if we were to start with n = 1000 llamas, at the end of the year, we would have 1000 / 3 = 333.33 new llamas. We can’t have a decimal portion of a llama, though, so we’ll truncate the decimal to get 333 new llamas born. 1000 / 4 = 250 llamas will pass away, so we’ll end up with a total of 1000 + 333 - 250 = 1083 llamas at the end of the year.

### Solution

[HERE](https://submit.cs50.io/users/jd-apprentice/cs50/labs/2023/x/population)

```c
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
```