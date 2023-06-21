/*
 * Name: Zeyad Amr
 * Sec: 1
 * B.N: 7
 *
 * Lab 5 - Keypad
 * Seven Segments Driver
 * seven_segements.c
 * This driver is used to display numbers from 0 to 9 on seven segments
 *
 */

#include "seven_segements.h"

void Segments_init()
{
    uint8 i = 0;
    for (i = 0; i < 7; i++)
    {
        Gpio_ConfigPin(Segment_Port, i, Segment_Mode, Segment_Default_State, Segment_PUPDR);
    }
}

void Segment_display(uint8 number)
{

    switch (number)
    {
    case 0:
        Gpio_WritePin(Segment_Port, 0, HIGH);
        Gpio_WritePin(Segment_Port, 1, HIGH);
        Gpio_WritePin(Segment_Port, 2, HIGH);
        Gpio_WritePin(Segment_Port, 3, HIGH);
        Gpio_WritePin(Segment_Port, 4, HIGH);
        Gpio_WritePin(Segment_Port, 5, HIGH);
        Gpio_WritePin(Segment_Port, 6, LOW);
        break;

    case 1:
        Gpio_WritePin(Segment_Port, 0, LOW);
        Gpio_WritePin(Segment_Port, 1, HIGH);
        Gpio_WritePin(Segment_Port, 2, HIGH);
        Gpio_WritePin(Segment_Port, 3, LOW);
        Gpio_WritePin(Segment_Port, 4, LOW);
        Gpio_WritePin(Segment_Port, 5, LOW);
        Gpio_WritePin(Segment_Port, 6, LOW);
        break;

    case 2:
        Gpio_WritePin(Segment_Port, 0, HIGH);
        Gpio_WritePin(Segment_Port, 1, HIGH);
        Gpio_WritePin(Segment_Port, 2, LOW);
        Gpio_WritePin(Segment_Port, 3, HIGH);
        Gpio_WritePin(Segment_Port, 4, HIGH);
        Gpio_WritePin(Segment_Port, 5, LOW);
        Gpio_WritePin(Segment_Port, 6, HIGH);
        break;

    case 3:
        Gpio_WritePin(Segment_Port, 0, HIGH);
        Gpio_WritePin(Segment_Port, 1, HIGH);
        Gpio_WritePin(Segment_Port, 2, HIGH);
        Gpio_WritePin(Segment_Port, 3, HIGH);
        Gpio_WritePin(Segment_Port, 4, LOW);
        Gpio_WritePin(Segment_Port, 5, LOW);
        Gpio_WritePin(Segment_Port, 6, HIGH);
        break;

    case 4:
        Gpio_WritePin(Segment_Port, 0, LOW);
        Gpio_WritePin(Segment_Port, 1, HIGH);
        Gpio_WritePin(Segment_Port, 2, HIGH);
        Gpio_WritePin(Segment_Port, 3, LOW);
        Gpio_WritePin(Segment_Port, 4, LOW);
        Gpio_WritePin(Segment_Port, 5, HIGH);
        Gpio_WritePin(Segment_Port, 6, HIGH);
        break;

    case 5:
        Gpio_WritePin(Segment_Port, 0, HIGH);
        Gpio_WritePin(Segment_Port, 1, LOW);
        Gpio_WritePin(Segment_Port, 2, HIGH);
        Gpio_WritePin(Segment_Port, 3, HIGH);
        Gpio_WritePin(Segment_Port, 4, LOW);
        Gpio_WritePin(Segment_Port, 5, HIGH);
        Gpio_WritePin(Segment_Port, 6, HIGH);
        break;

    case 6:
        Gpio_WritePin(Segment_Port, 0, HIGH);
        Gpio_WritePin(Segment_Port, 1, LOW);
        Gpio_WritePin(Segment_Port, 2, HIGH);
        Gpio_WritePin(Segment_Port, 3, HIGH);
        Gpio_WritePin(Segment_Port, 4, HIGH);
        Gpio_WritePin(Segment_Port, 5, HIGH);
        Gpio_WritePin(Segment_Port, 6, HIGH);
        break;

    case 7:
        Gpio_WritePin(Segment_Port, 0, HIGH);
        Gpio_WritePin(Segment_Port, 1, HIGH);
        Gpio_WritePin(Segment_Port, 2, HIGH);
        Gpio_WritePin(Segment_Port, 3, LOW);
        Gpio_WritePin(Segment_Port, 4, LOW);
        Gpio_WritePin(Segment_Port, 5, LOW);
        Gpio_WritePin(Segment_Port, 6, LOW);
        break;

    case 8:
        Gpio_WritePin(Segment_Port, 0, HIGH);
        Gpio_WritePin(Segment_Port, 1, HIGH);
        Gpio_WritePin(Segment_Port, 2, HIGH);
        Gpio_WritePin(Segment_Port, 3, HIGH);
        Gpio_WritePin(Segment_Port, 4, HIGH);
        Gpio_WritePin(Segment_Port, 5, HIGH);
        Gpio_WritePin(Segment_Port, 6, HIGH);
        break;

    case 9:
        Gpio_WritePin(Segment_Port, 0, HIGH);
        Gpio_WritePin(Segment_Port, 1, HIGH);
        Gpio_WritePin(Segment_Port, 2, HIGH);
        Gpio_WritePin(Segment_Port, 3, HIGH);
        Gpio_WritePin(Segment_Port, 4, LOW);
        Gpio_WritePin(Segment_Port, 5, HIGH);
        Gpio_WritePin(Segment_Port, 6, HIGH);
        break;

    default:
        Gpio_WritePin(Segment_Port, 0, LOW);
        Gpio_WritePin(Segment_Port, 1, LOW);
        Gpio_WritePin(Segment_Port, 2, LOW);
        Gpio_WritePin(Segment_Port, 3, LOW);
        Gpio_WritePin(Segment_Port, 4, LOW);
        Gpio_WritePin(Segment_Port, 5, LOW);
        Gpio_WritePin(Segment_Port, 6, LOW);

        break;
    }
}
