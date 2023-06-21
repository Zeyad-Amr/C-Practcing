// Lab 08
// EXTI.c
// Name : Zeyad Amr Fekry
// Sec: 1
// B.N: 37

#include "EXTI.h"

void Exti_Init(uint8 source_input, uint8 line)
{
    // Set source input
    SYSCFG_Register->EXTICR1 &= ~(0xF0 << line * 4);
    SYSCFG_Register->EXTICR1 |= (source_input << line * 4);

    // Set edge detection
    SET_BIT(EXTI->FTSR, line); // falling edge dectection
}

void Exti_Enable(uint8 port, uint8 line, uint8 position)
{

    SET_BIT(EXTI->IMR, line); // enable exti

    SET_BIT(NVIC_ISER0, position); // enable line on nvic

    Gpio_ConfigPin(port, line, GPIO_INPUT, GPIO_PUSH_PULL, GPIO_PULL_UP);
}

void Exti_Disable(uint8 line)
{
    SET_BIT(EXTI->IMR, line); // disable exti
}
