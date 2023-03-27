#include <stdio.h>
int main()
{
    // scanf example

    char a = 'M';

    // b = ref address of a variable
    char *b = &a;

    printf("b = %p\n", b);

    // print the value of a by dereferencing b
    printf("*b = %c\n", *b);

    float c = 100.1;

    printf("Enter a character: ");

    scanf("%c", &a);

    printf("Enter an integer: ");

    scanf("%i", &b);

    printf("Enter a float: ");

    scanf("%f", &c);

    printf("a= %c, b= %i, c= %f", a, b, c);

    return 0;
}