#include <stdio.h>

int main()
{

    printf(" Bitwise Operator ######################################\n");

    unsigned char a = 9; // 0000 1001
    unsigned char b = 5; // 0000 0101

    printf("a&b = %d\n", a & b);   // 0000 0001 = 1
    printf("a|b = %d\n", a | b);   // 0000 1101 = 13
    printf("a^b = %d\n", a ^ b);   // 0000 1100 = 12
    printf("~a = %d\n", ~a);       // 1111 0110 = -10
    printf("~b = %d\n", ~b);       // 1111 1010 = -6
    printf("a<<1 = %d\n", a << 1); // 0001 0010 = 18
    printf("a>>1 = %d\n", a >> 1); // 0000 0100 = 4
    printf("b<<2 = %d\n", b << 2); // 0001 0100 = 20
    printf("b>>2 = %d\n", b >> 2); // 0000 0001 = 1

    printf(" Bit Masking ######################################\n");

    unsigned char c = 0b00000011; // 0000 0011
    unsigned char d = 0b00001100; // 0000 1100
    unsigned char x = 1 << 3;     // 0000 1000
    unsigned char y = ~(1 << 3);  // 1111 0111
    // set bit 3

    printf("set bit 3 at c = %d\n", c | x); // 0000 1011 = 11

    // reset bit 3

    printf("reset bit 3 at d = %d\n", d & y); // 0000 0100 = 4

    // toggle bit 3
    printf("toggle bit 3 at c = %d\n", c ^ x); // 0000 1011 = 11
    printf("toggle bit 3 at d = %d\n", d ^ x); // 0000 0100 = 4

    // check bit 3
    printf("check bit 3 at c = %d\n", (c & x) >> 3); // 0000 0000 = 0
    printf("check bit 3 at d = %d\n", (d & x) >> 3); // 0000 0001 = 1

    return 0;
}