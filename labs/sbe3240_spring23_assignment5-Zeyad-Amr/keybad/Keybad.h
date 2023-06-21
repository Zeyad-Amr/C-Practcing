/*
 * Name: Zeyad Amr
 * Sec: 1
 * B.N: 7
 *
 * Lab 5 - Keypad
 * Keybad Driver
 * Keybad.h
 * This driver is used to manage the keybad
 *
 */

#ifndef KEYBAD_H_
#define KEYBAD_H_

/* ------------------------- Libraries ------------------------- */
#include "Gpio.h"
#include "Std_Types.h"

/* ------------------------- Cols Configurations ------------------------- */
#define Keybad_Cols_Port GPIO_B
#define Keybad_Cols_Number 3
#define Keybad_Cols__Start_Pin 0
#define Keybad_Cols__End_Pin 2
#define Keybad_Cols_PUPDR GPIO_PULL_UP
#define Keybad_Cols_Default_State GPIO_PUSH_PULL
#define Keybad_Cols_Mode GPIO_OUTPUT

/* ------------------------- Rows Configurations ------------------------- */
#define Keybad_Rows_Port GPIO_B
#define Keybad_Rows_Number 4
#define Keybad_Rows__Start_Pin 3
#define Keybad_Rows__End_Pin 6
#define Keybad_Rows_PUPDR GPIO_PULL_UP
#define Keybad_Rows_Default_State GPIO_PUSH_PULL
#define Keybad_Rows_Mode GPIO_INPUT

/* ------------------------- Keybad Configurations ------------------------- */
#define Keybad_Button_Pressed 0
#define Keybad_Button_Released 1

/* ------------------------- Keybad Functions Prototypes ------------------------- */
void Keybad_init(void);
void Keybad_manage(void);
uint8 Keypad_GetKey(void);
void delay_ms(unsigned long time);
void KeypadCallouts_KeyPressNotificaton();

#endif /* KEYBAD_H_ */
