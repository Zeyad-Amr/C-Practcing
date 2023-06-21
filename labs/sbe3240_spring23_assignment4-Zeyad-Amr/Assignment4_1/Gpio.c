// Lab 04 Assignment
// Gpio.c
// Name : Zeyad Amr Fekry
// Sec: 1
// B.N: 37

#include "Gpio.h"

#include "Gpio_Private.h"
#include "Utils.h"

void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode,
                    uint8 DefaultState, uint8 PUPDR)
{

  switch (PortName)
  {
  case GPIO_A:
    GPIOA_MODER &= ~(0x03 << (PinNum * 2));
    GPIOA_MODER |= (PinMode << (PinNum * 2));

    GPIOA_OTYPER &= ~(0x01 << PinNum);
    GPIOA_OTYPER |= (DefaultState << PinNum);

    GPIOA_PUPDR &= ~(0x03 << (PinNum * 2));
    GPIOA_PUPDR |= (PUPDR << (PinNum * 2));
    break;
  case GPIO_B:
    GPIOB_MODER &= ~(0x03 << (PinNum * 2));
    GPIOB_MODER |= (PinMode << (PinNum * 2));

    GPIOB_OTYPER &= ~(0x01 << PinNum);
    GPIOB_OTYPER |= (DefaultState << PinNum);

    GPIOB_PUPDR &= ~(0x03 << (PinNum * 2));
    GPIOB_PUPDR |= (PUPDR << (PinNum * 2));
    break;
  case GPIO_C:
    GPIOC_MODER &= ~(0x03 << (PinNum * 2));
    GPIOC_MODER |= (PinMode << (PinNum * 2));

    GPIOC_OTYPER &= ~(0x01 << PinNum);
    GPIOC_OTYPER |= (DefaultState << PinNum);

    GPIOC_PUPDR &= ~(0x03 << (PinNum * 2));
    GPIOC_PUPDR |= (PUPDR << (PinNum * 2));
    break;
  case GPIO_D:
    GPIOD_MODER &= ~(0x03 << (PinNum * 2));
    GPIOD_MODER |= (PinMode << (PinNum * 2));

    GPIOD_OTYPER &= ~(0x01 << PinNum);
    GPIOD_OTYPER |= (DefaultState << PinNum);

    GPIOD_PUPDR &= ~(0x03 << (PinNum * 2));
    GPIOD_PUPDR |= (PUPDR << (PinNum * 2));

    break;
  default:
    break;
  }
}

uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data)
{

  switch (PortName)
  {
  case GPIO_A:
    // check if the pin is output
    if (((GPIOA_MODER & (0x03 << (PinNum * 2))) >> (PinNum * 2)) != GPIO_OUTPUT)
    {
      return NOK;
    }
    GPIOA_ODR &= ~(0x1 << PinNum);
    GPIOA_ODR |= (Data << PinNum);
    break;
  case GPIO_B:
    // check if the pin is output
    if (((GPIOB_MODER & (0x03 << (PinNum * 2))) >> (PinNum * 2)) != GPIO_OUTPUT)
    {
      return NOK;
    }
    GPIOB_ODR &= ~(0x1 << PinNum);
    GPIOB_ODR |= (Data << PinNum);
    break;
  case GPIO_C:
    // check if the pin is output
    if (((GPIOC_MODER & (0x03 << (PinNum * 2))) >> (PinNum * 2)) != GPIO_OUTPUT)
    {
      return NOK;
    }
    GPIOC_ODR &= ~(0x1 << PinNum);
    GPIOC_ODR |= (Data << PinNum);
    break;
  case GPIO_D:
    // check if the pin is output
    if (((GPIOD_MODER & (0x03 << (PinNum * 2))) >> (PinNum * 2)) != GPIO_OUTPUT)
    {
      return NOK;
    }
    GPIOD_ODR &= ~(0x1 << PinNum);
    GPIOD_ODR |= (Data << PinNum);
    break;
  default:
    break;
  }

  return OK;
}
