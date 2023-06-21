/*
 * Name: Zeyad Amr
 * Sec: 1
 * B.N: 7
 *
 * Lab 5 - Keypad
 * Seven Segments Driver
 * seven_segements.h
 * This driver is used to display numbers from 0 to 9 on seven segments
 *
 */
#ifndef SEVEN_SEGEMENTS_H_
#define SEVEN_SEGEMENTS_H_

/* ------------------------- Libraries ------------------------- */
#include "Gpio.h"
#include "Std_Types.h"

/* ------------------------- Cols Configurations ------------------------- */
#define Segment_Port GPIO_A
#define Segment_PUPDR GPIO_PULL_UP
#define Segment_Default_State GPIO_PUSH_PULL
#define Segment_Mode GPIO_OUTPUT

void Segments_init();
void Segment_display(uint8 number);

#endif /* SEVEN_SEGEMENTS_H_ */
