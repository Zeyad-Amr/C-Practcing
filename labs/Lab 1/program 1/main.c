#include <stdio.h>

// Function prototypes
float final_velocity(float u, float a, float t);
float distance(float u, float a, float t);

int main()
{
    // initialize variables
    float u = 0, a = 0, t = 0;

    // get user inputs
    printf("Enter Initial Velocity (m/s): ");
    scanf("%f", &u);

    printf("Enter Acceleration (m/s^2): ");
    scanf("%f", &a);

    printf("Enter Time (s): ");
    scanf("%f", &t);

    // print results
    printf("Final Velocity: %f m/s \n", final_velocity(u, a, t));
    printf("Distance: %f m \n", distance(u, a, t));

    return 0;
}

// Function definitions

float final_velocity(float u, float a, float t)
{
    return u + a * t;
}

float distance(float u, float a, float t)
{
    return u * t + 0.5 * a * t * t;
}