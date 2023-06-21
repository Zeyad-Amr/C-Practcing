// Lab 08
// EXTI.h
// Name : Zeyad Amr Fekry
// Sec: 1
// B.N: 37

#ifndef EXTI_H_
#define EXTI_H_

#include "Bit_Operations.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"

// SYSCFG_EXTICR1_EXTI0_X defines
#define SYSCFG_EXTICR1_EXTI0_PA 0x0000
#define SYSCFG_EXTICR1_EXTI0_PB 0x0001
#define SYSCFG_EXTICR1_EXTI0_PC 0x0002
#define SYSCFG_EXTICR1_EXTI0_PD 0x0003
#define SYSCFG_EXTICR1_EXTI0_PE 0x0004
#define SYSCFG_EXTICR1_EXTI0_PH 0x0007

// EXTI Postions in NVIC Postions
#define EXTI0_POSTION 6
#define EXTI1_POSTION 7
#define EXTI2_POSTION 8
#define EXTI3_POSTION 9
#define EXTI4_POSTION 10

// NVIC Register
#define NVIC_ISER0 (*(uint32 *)0xE000E100)

// EXIT Registers
typedef struct
{
	uint32 IMR;
	uint32 EMR;
	uint32 RTSR;
	uint32 FTSR;
	uint32 SWIER;
	uint32 PR;
} ExtiType;

#define EXTI ((ExtiType *)0x40013C00)

// SYSCFG Register
#define SYSCFG_Register ((SYSCFG_Register_Type *)0x40013800)
typedef struct
{
	uint32 CMPCR;
	uint32 PMC;
	uint32 EXTICR1;
	uint32 EXTICR2;
	uint32 EXTICR3;
	uint32 EXTICR4;
	uint32 MEMRMP;
} SYSCFG_Register_Type;

// Prototypes
void Exti_Init(uint8 source_input, uint8 line);
void Exti_Enable(uint8 port, uint8 line, uint8 position);
void Exti_Disable(uint8 line);

#endif /* EXTI_H_ */
