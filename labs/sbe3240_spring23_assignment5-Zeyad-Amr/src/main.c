/*
 * Name: Zeyad Amr
 * Sec: 1
 * B.N: 7
 *
 * Lab 5 - Keypad
 * main.c
 * Main file for the project
 *
 */

#include "Rcc.h"
#include "GPIO.h"
#include "Keybad.h"
#include "seven_segements.h"

// Main Function
int main()
{
	// Initialize RCC
	Rcc_Init();
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_GPIOA);

	// Initialize Keypad
	Keybad_init();

	// Initialize 7-segment
	Segments_init();

	// main loop
	while (1)
	{
		Keybad_manage();
	}

	return 0;
}

void KeypadCallouts_KeyPressNotificaton()
{
	// Display the pressed key on 7-segment
	Segment_display(Keypad_GetKey());
}
