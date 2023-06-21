// Lab 04 Homework
// main.c
// Name : Zeyad Amr Fekry
// Sec: 1
// B.N: 37

#include "main.h"

// Main Function
int main()
{
	// Enable the clock for RCC (RCC_AHB1ENR) for GPIOB
	rcc_enable(RCC_AHBIENR_GPIOB);

	// Initialize the LEDs
	led_init(Red_LED_PIN);
	led_init(Green_LED_PIN);
	led_init(Blue_LED_PIN);

	// Initialize the Button
	button_init(BUTTON_PIN);

	unsigned int mode = 0;
	unsigned char flag = 0;

	// infinte Loop
	while (1)
	{
		// Check if the button is pressed
		if (GPIO_ReadPin(GPIO_B, BUTTON_PIN) == LOW)
		{
			// Wait for 30 ms
			delay_ms(30);

			// Check if the button is still pressed
			if (GPIO_ReadPin(GPIO_B, BUTTON_PIN) == LOW && !flag)
			{
				mode++;
				if (mode > 7)
				{
					mode = 0;
				}

				led_flash(mode);

				// Delay for 0.3 second
				delay_ms(300);
			}
		}
		else
		{
			// Reset the flag
			flag = 0;
		}
	}
	return 0;
}

// Functions Definition

void rcc_enable(unsigned char gpio_bit)
{
	// Enable the clock for RCC (RCC_AHB1ENR) for GPIOB
	RCC_AHB1ENR |= (1 << gpio_bit);
}

void led_init(unsigned char pin)
{
	Gpio_ConfigPin(GPIO_B, pin, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_NO_PULL);
}

void button_init(unsigned char pin)
{
	Gpio_ConfigPin(GPIO_B, pin, GPIO_INPUT, GPIO_PUSH_PULL, GPIO_PULL_UP);
}

void delay_ms(unsigned long time)
{
	// calc the number of cycles
	time *= 4000;

	for (int i = 0; i < time; i++)
	{
		__asm("NOP");
	}
}

void led_flash(unsigned int mode)
{
	switch (mode)
	{
	case 0:
		turn_off_led(Red_LED_PIN);
		turn_off_led(Green_LED_PIN);
		turn_off_led(Blue_LED_PIN);
		break;

	case 1:
		turn_on_led(Red_LED_PIN);
		turn_off_led(Green_LED_PIN);
		turn_off_led(Blue_LED_PIN);
		break;

	case 2:
		turn_off_led(Red_LED_PIN);
		turn_on_led(Green_LED_PIN);
		turn_off_led(Blue_LED_PIN);
		break;

	case 3:
		turn_on_led(Red_LED_PIN);
		turn_on_led(Green_LED_PIN);
		turn_off_led(Blue_LED_PIN);
		break;

	case 4:
		turn_off_led(Red_LED_PIN);
		turn_off_led(Green_LED_PIN);
		turn_on_led(Blue_LED_PIN);
		break;

	case 5:
		turn_on_led(Red_LED_PIN);
		turn_off_led(Green_LED_PIN);
		turn_on_led(Blue_LED_PIN);
		break;

	case 6:
		turn_off_led(Red_LED_PIN);
		turn_on_led(Green_LED_PIN);
		turn_on_led(Blue_LED_PIN);
		break;

	case 7:
		turn_on_led(Red_LED_PIN);
		turn_on_led(Green_LED_PIN);
		turn_on_led(Blue_LED_PIN);
		break;

	default:
		break;
	}
}

void turn_off_led(unsigned char pin)
{
	Gpio_WritePin(GPIO_B, pin, LOW);
}

void turn_on_led(unsigned char pin)
{
	Gpio_WritePin(GPIO_B, pin, HIGH);
}
