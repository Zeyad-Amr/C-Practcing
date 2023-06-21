// Lab 04 Assignment
// Gpio.h
// Name : Zeyad Amr Fekry
// Sec: 1
// B.N: 37

#ifndef GPIO_H
#define GPIO_H
#include "Std_Types.h"

/*PortName*/
#define GPIO_A 'A'
#define GPIO_B 'B'
#define GPIO_C 'C'
#define GPIO_D 'D'

/*PinMode*/
#define GPIO_INPUT 0x00
#define GPIO_OUTPUT 0x01
#define GPIO_AF 0x02
#define GPIO_ANALOG 0x03

/*PUPDR*/
#define GPIO_NO_PULL 0x00
#define GPIO_PULL_UP 0x01
#define GPIO_PULL_DOWN 0x02
#define GPIO_RESERVED 0x03

/*DefaultState*/
#define GPIO_PUSH_PULL 0x00
#define GPIO_OPEN_DRAIN 0x01

/*Data*/
#define LOW 0x00
#define HIGH 0x01

#define NOK 0x00
#define OK 0x01

void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState, uint8 PUPDR);

uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data);

#endif /* GPIO_H */
