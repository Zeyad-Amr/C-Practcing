#include <stdio.h>
int main()
{

    char a = 'a';
    int b = 97;
    float c = 100.1;
    double d = 100.1;

    printf("%d\n%d\n%d\n%d\n", sizeof(a), sizeof(b), sizeof(c), sizeof(d));

    printf("%d\n", a);
    printf("%c\n", b);
    printf("%f\n", c);
    printf("%i\n", (int)c);
    printf("%f\n", d);

    double z = 5.5;
    printf("%d\n", z);
    printf("%f\n", z);

    int x;
    x = c;
    printf("x f = %f\n", x);
    printf("x i = %i\n", x);

    short int y = 19000000;
    printf("%i", y);

    return 0;
}