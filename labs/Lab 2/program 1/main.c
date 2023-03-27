#include <stdio.h>

// Functions prototypes

unsigned char rotate_left(unsigned char number, int cycles);
unsigned char rotate_right(unsigned char number, int cycles);
void print_binary(unsigned char number);

int main()
{
    // initialize variables
    unsigned char number = 0; // 8 bit number
    int cycles = 0;           // number of cycles
    char direction = 'l';     // direction of rotation

    // get user input
    printf("Enter an 8 bit number: ");
    scanf("%hhu", &number);

    printf("Enter the number of cycles: ");
    scanf("%d", &cycles);

    printf("Enter the direction (l/r): ");
    scanf(" %c", &direction);

    // print the number in binary
    printf("The number in binary is: ");
    print_binary(number);

    // rotate the number
    if (direction == 'l')
    {
        number = rotate_left(number, cycles);
    }
    else if (direction == 'r')
    {
        number = rotate_right(number, cycles);
    }
    else
    {
        printf("Invalid direction");
        return 1;
    }

    // print the result
    printf("The result is: %i\n", number);
    printf("The result in binary is: ");
    print_binary(number);

    return 0;
}

// Function definitions

unsigned char rotate_left(unsigned char number, int cycles)
{
    return (number << cycles) | (number >> (8 - cycles));
}

unsigned char rotate_right(unsigned char number, int cycles)
{
    return (number >> cycles) | (number << (8 - cycles));
}

void print_binary(unsigned char number)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%i", (number >> i) & 1);
    }
    printf("\n");
}