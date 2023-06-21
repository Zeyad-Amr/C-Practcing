// Lab 03 Homework
// main.c
// Name : Zeyad Amr Fekry
// Sec: 1
// B.N: 37

// Registers Definitions
#define RCC 0x40023800
#define RCC_AHB1ENR (*(unsigned long *)(RCC + 0x30))
#define GPIOB_BASE_ADDR 0x40020400
#define GPIOB_MODER (*(unsigned long *)(GPIOB_BASE_ADDR + 0x00))
#define GPIOB_OTYPER (*(unsigned long *)(GPIOB_BASE_ADDR + 0x04))
#define GPIOB_ODR (*(unsigned long *)(GPIOB_BASE_ADDR + 0x14))
#define GPIOB_IDR (*(unsigned long *)(GPIOB_BASE_ADDR + 0x10))
#define GPIOB_PUPDR (*(unsigned long *)(GPIOB_BASE_ADDR + 0X0C))
#define RCC_AHBIENR_GPIOB 1

// Pins Definitions
#define BUTTON_PIN 3
#define Red_LED_PIN 5
#define Green_LED_PIN 6
#define Blue_LED_PIN 7

// Functions Headers
void rcc_enable(unsigned char gpio_bit);
void led_init(unsigned char pin);
void button_init(unsigned char pin);
void delay_ms(unsigned long time);
void led_flash(unsigned int mode);
void turn_off_led(unsigned char pin);
void turn_on_led(unsigned char pin);

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
		if ((!(GPIOB_IDR & (1 << BUTTON_PIN))))
		{
			// Wait for 30 ms
			delay_ms(30);

			// Check if the button is still pressed
			if (!(GPIOB_IDR & (1 << BUTTON_PIN)) && !flag)
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

	GPIOB_MODER &= ~(0x03 << (pin * 2)); // Clear pin

	GPIOB_MODER |= (1 << (pin * 2)); // Set pin to output mode

	GPIOB_OTYPER &= ~(1 << pin); // Set pin to push-pull

	turn_off_led(pin);
}

void button_init(unsigned char pin)
{
	//  Set pin of as input mode
	GPIOB_MODER &= ~(0x3 << pin * 2);

	// Set pin of as pull-up input
	GPIOB_PUPDR &= ~(0x01 << 2 * pin);
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
	GPIOB_ODR &= ~(1 << pin);
}

void turn_on_led(unsigned char pin)
{
	GPIOB_ODR |= (1 << pin);
}