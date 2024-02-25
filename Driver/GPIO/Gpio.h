#ifndef GPIO_H
#define GPIO_H

#include "Gpio_Registers.h"

#define PORTA           2
#define PORTB           3
#define PORTC           4
#define PORTD           5
#define PORTE           6

#define INPUT_MODE 		0
#define OUTPUT_MODE 	1

#define ANALOG_MODE     0
#define FLOAT_INPUT     1
#define PULL_INPUT      2

#define PULL_UP 		1
#define PULL_DOWN   	0

#define LOW				0
#define HIGH 			1

typedef struct
{
    GPIO_Type         *      base;                  /*!< Gpio base pointer.*/
    unsigned char            GPIO_PORT;             /*!< PORT.*/
    unsigned char            GPIO_PinNumber;        /*!< Pin number.*/
    unsigned char            GPIO_PinMode;          /*!< MODEy.*/
    unsigned char            GPIO_CNF;              /*!< CNFy.*/
    unsigned char            Pull_config;           /*!< Pull up, pull down*/
} Gpio_ConfigType;


void Gpio_Init(const Gpio_ConfigType* ConfigPtr);
void GPIO_WriteToOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber, unsigned char value);
void GPIO_SetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);
void GPIO_ResetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);
void GPIO_ToggleOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);
unsigned char GPIO_ReadFromInputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);
char check_GPIO_parameter(unsigned char PinNumber);

#endif

/*
void GPIO_OUPUT_init(void)
{
		GPIO_Cn.base = GPIOx;
		GPIO_Cn.GPIO_PORT = PORTx;
		GPIO_Cn.GPIO_PinNumber = n;		
		GPIO_Cn.GPIO_PinMode = OUTPUT_MODE;
	
		Gpio_Init(&GPIO_Cn);
}

void GPIO_INPUT_init(void)
{
		GPIO_Cn.base = GPIOx;
		GPIO_Cn.GPIO_PORT = PORTx;
		GPIO_Cn.GPIO_PinNumber = n;		
		GPIO_Cn.GPIO_PinMode = INPUT_MODE;
		GPIO_Cn.GPIO_CNF = PULL_INPUT;
		GPIO_Cn.Pull_config = PULL_UP;
		Gpio_Init(&GPIO_Cn);
}
*/