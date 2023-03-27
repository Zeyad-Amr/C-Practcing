#include <stdio.h>

float taylor_series(int exp, int iterations);

int main()
{
    // Declare variables
    int exp, iterations;

    // Get user input
    printf("Enter the exponent: ");
    scanf("%d", &exp);

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    // Print the result
    printf("The result is: %f\n", taylor_series(exp, iterations));
}

// Taylor Series for e^x is: 1 + x/1! + x^2/2! + x^3/3! + x^4/4! + ... + x^n/n!

// exp = x
// iterations = n
float taylor_series(int exp, int iterations)
{
    // Declare variables
    float result = 1;  // 1 is the first term of the series
    int factorial = 1; // 1! = 1
    int power = 1;     // x^0 = 1

    for (int i = 1; i <= iterations; ++i)
    {
        // Calculate the factorial
        factorial *= i;

        // Calculate the power
        power *= exp;

        // Add the term to the result
        result += (float)power / factorial;
    }
    return result;
}