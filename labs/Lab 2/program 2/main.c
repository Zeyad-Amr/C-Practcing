#include <stdio.h>

int main()
{
    // Declare Size of the diamond
    int size = 9;

    // Loop through the rows
    for (int row = 0; row < size; row++)
    {
        // Calculate the distance from the center
        int distance_from_center = row < size / 2 ? row : size - row - 1;

        // Loop through the columns
        for (int col = 0; col < size; col++)
        {
            // Print the star or space
            if (col < size / 2 - distance_from_center || col > size / 2 + distance_from_center)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }

        // Print a new line
        printf("\n");
    }
    return 0;
}
