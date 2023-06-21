// Lab 04 Homework
// main.h
// Name : Zeyad Amr Fekry
// Sec: 1
// B.N: 37

#ifndef MAIN_H_
#define MAIN_H_

#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"

#define RCC 0x40023800
#define RCC_AHBIENR_GPIOB 1
#define RCC_AHB1ENR (*(unsigned long *)(RCC + 0x30))

// Pins Definitions
#define BUTTON_PIN 3
#define Red_LED_PIN 5
#define Green_LED_PIN 6
#define Blue_LED_PIN 7

// Functions Headers
void led_init(unsigned char pin);
void button_init(unsigned char pin);
void delay_ms(unsigned long time);
void led_flash(unsigned int mode);
void turn_off_led(unsigned char pin);
void turn_on_led(unsigned char pin);

#endif /* GPIO_H */
