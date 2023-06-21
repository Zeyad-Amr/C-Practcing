/*
 * Name: Zeyad Amr
 * Sec: 1
 * B.N: 7
 *
 * Lab 5 - Keypad
 * Keybad Driver
 * Keybad.c
 * This driver is used to manage the keybad
 *
 */

#include "Keybad.h"

uint8 key = 0;
uint8 flag = 0;

void Keybad_init(void)
{
    uint8 i;

    for (i = Keybad_Cols__Start_Pin; i <= Keybad_Cols__End_Pin; i++)
    {
        // Configure the columns pins
        Gpio_ConfigPin(Keybad_Cols_Port, i, Keybad_Cols_Mode, Keybad_Cols_Default_State, Keybad_Cols_PUPDR);

        // Set the column to low
        Gpio_WritePin(Keybad_Cols_Port, i, Keybad_Button_Released);
    }

    for (i = Keybad_Rows__Start_Pin; i <= Keybad_Rows__End_Pin; i++)
    {
        // Configure the rows pins
        Gpio_ConfigPin(Keybad_Rows_Port, i, Keybad_Rows_Mode, Keybad_Rows_Default_State, Keybad_Rows_PUPDR);
    }
}

void Keybad_manage(void)
{

    for (uint8 i = Keybad_Cols__Start_Pin; i <= Keybad_Cols__End_Pin; i++)
    {

        // Set the current column to high
        Gpio_WritePin(Keybad_Cols_Port, i, Keybad_Button_Pressed);

        // Check if any button is pressed in the current column
        for (uint8 j = Keybad_Rows__Start_Pin; j <= Keybad_Rows__End_Pin; j++)
        {

            // Check if the button is pressed
            if (Gpio_ReadPin(Keybad_Rows_Port, j) == Keybad_Button_Pressed)
            {
                // Check if the button is still pressed after 30ms
                delay_ms(30);

                if (Gpio_ReadPin(Keybad_Rows_Port, j) == Keybad_Button_Pressed && flag == 0)
                {
                    // flag to check gettting the key value from GetKey function
                    flag = 1;

                    // Set the key value
                    key = (j - Keybad_Rows__Start_Pin) * Keybad_Cols_Number + (i - Keybad_Cols__Start_Pin) + 1;

                    // set the key value to 0 if the key is * or # or 0
                    if (key > 9)
                        key = 0;

                    // call the callout function to notify the user that a key is pressed
                    KeypadCallouts_KeyPressNotificaton();
                }
            }
        }

        // Set the current column to low
        Gpio_WritePin(Keybad_Cols_Port, i, Keybad_Button_Released);
    }
}

uint8 Keypad_GetKey(void)
{
    // flag to check gettting the key value from GetKey function
    flag = 0;

    // return the key value
    return key;
}

void delay_ms(uint32 miliseconds)
{
    miliseconds *= 1000;

    for (uint32 i = 0; i < miliseconds; i++)
    {
        __asm("NOP");
    }
}
