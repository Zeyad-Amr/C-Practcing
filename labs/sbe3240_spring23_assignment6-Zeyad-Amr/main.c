// Lab 08
// main.c
// Name : Zeyad Amr Fekry
// Sec: 1
// B.N: 37

#include "seven_segements.h"
#include "EXTI.h"

// Initialize Counter to 0
int counter = 0;

int main()
{
	// Initialize RCC
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_SYSCFG);

	// Initialize 7-segment
	Segments_init();

	// Display 0
	Segments_display(counter);

	// Initialize EXTI
	Exti_Init(SYSCFG_EXTICR1_EXTI0_PB, 0);
	Exti_Init(SYSCFG_EXTICR1_EXTI0_PB, 1);

	// Enable EXTI
	Exti_Enable(GPIO_B, 0, EXTI0_POSTION);
	Exti_Enable(GPIO_B, 1, EXTI1_POSTION);

	//  Infinite loop
	while (1)
	{
	}

	return 0;
}

void EXTI0_IRQHandler(void)
{
	// increment counter
	if (counter < 9)
		counter++;

	// display counter
	Segments_display(counter);

	// clear pending flag
	SET_BIT(EXTI->PR, 0);
}

void EXTI1_IRQHandler(void)
{
	// decrement counter
	if (counter > 0)
		counter--;

	// display counter
	Segments_display(counter);

	// clear pending flag
	SET_BIT(EXTI->PR, 1);
}
