#include <stdio.h>

int sum(int n1, int n2, int n3);
float average(int n1, int n2, int n3);
int product(int n1, int n2, int n3);
int smallest(int n1, int n2, int n3);
int largest(int n1, int n2, int n3);

int main()
{

    // initialize variables
    int n1 = 0, n2 = 0, n3 = 0;

    // get user inputs
    printf("Enter 3 integers: ");
    scanf("%i %i %i", &n1, &n2, &n3);

    // print results
    printf("Sum is %i \n", sum(n1, n2, n3));
    printf("Average is %f \n", average(n1, n2, n3));
    printf("Product is %i \n", product(n1, n2, n3));
    printf("Smallest is %i \n", smallest(n1, n2, n3));
    printf("Largest is %i \n", largest(n1, n2, n3));

    return 0;
}

int sum(int n1, int n2, int n3)
{
    return n1 + n2 + n3;
}

float average(int n1, int n2, int n3)
{
    return (n1 + n2 + n3) / 3.0;
}

int product(int n1, int n2, int n3)
{
    return n1 * n2 * n3;
}

int smallest(int n1, int n2, int n3)
{
    int smallest = (n1 < n2) * n1 + (n1 >= n2) * n2;
    smallest = (smallest < n3) * smallest + (smallest >= n3) * n3;
    return smallest;
}

int largest(int n1, int n2, int n3)
{
    int largest = (n1 > n2) * n1 + (n1 <= n2) * n2;
    largest = (largest > n3) * largest + (largest <= n3) * n3;
    return largest;
}

/*
--> another way to do it is to use the ternary operator

int smallest(int n1, int n2, int n3)
{
    return (n1 < n2 && n1 < n3) ? n1 : (n2 < n3) ? n2 : n3;
}

*/
