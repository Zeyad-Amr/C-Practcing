#include <stdio.h>

int hours(int seconds);
int minutes(int seconds);
int seconds(int seconds);

int main()
{
    // initialize variables
    int secs = 0;

    // get user inputs
    printf("Enter the total time elapsed, in seconds: ");
    scanf("%i", &secs);

    // print results
    printf("%i : %i : %i \n", hours(secs), minutes(secs), seconds(secs));
}

int hours(int seconds)
{
    return seconds / 3600;
}

int minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

int seconds(int seconds)
{
    return (seconds % 3600) % 60;
}