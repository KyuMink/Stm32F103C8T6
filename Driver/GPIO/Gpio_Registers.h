#ifndef GPIO_REGISTER_H
#define GPIO_REGISTER_H

/** GPIO - Register Layout Typedef */
typedef struct {
  	volatile unsigned int CRL;
	volatile unsigned int CRH;
	volatile unsigned int IDR;
	volatile unsigned int ODR;
	volatile unsigned int BSRR;
	volatile unsigned int BRR;
	volatile unsigned int LCKR;
} GPIO_Type;

/** Peripheral GPIOA base address */
#define GPIOA_BASE		(0x40010800u)
#define GPIOB_BASE		(0x40010C00u)
#define GPIOC_BASE		(0x40011000u)
#define GPIOD_BASE		(0x40011400u)
#define GPIOE_BASE		(0x40011800u)

/** Peripheral GPIOA base pointer */
#define GPIOA    ((GPIO_Type *)GPIOA_BASE)
#define GPIOB    ((GPIO_Type *)GPIOB_BASE)
#define GPIOC    ((GPIO_Type *)GPIOC_BASE)
#define GPIOD    ((GPIO_Type *)GPIOD_BASE)
#define GPIOE    ((GPIO_Type *)GPIOE_BASE)

#define RCC_PORT_APB2ENR	(*(volatile unsigned int*) (0x40021000u + 0x18u))

#endif
