#include <stdio.h>

void print_fibonacci(int terms);

int main()
{
    // Declare the number of terms
    int terms;

    // Get the number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    // Check if the number of terms is valid
    if (terms < 0)
    {
        printf("The number of terms must be a positive integer.\n");
        return 1;
    }

    // Print the Fibonacci sequence
    print_fibonacci(terms);

    return 0;
}

void print_fibonacci(int terms)
{
    // Declare the first two terms
    int first = 0;
    int second = 1;
    int next = 0;

    // calculate the Fibonacci sequence
    for (int i = 0; i <= terms; i++)
    {
        if (i == 0)
        {
            printf("%d", first);
        }
        else if (i == 1)
        {
            printf(", %d", second);
        }
        else
        {
            next = first + second;
            first = second;
            second = next;
            printf(", %d", next);
        }
    }

    printf("\n");
}