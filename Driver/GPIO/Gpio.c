#include "Gpio.h"

char check_GPIO_parameter(unsigned char PinNumber) // miss check port E 17 pin
{		
	if ((PinNumber >18)||(PinNumber ==0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Gpio_Init(const Gpio_ConfigType* ConfigPtr)
{
//ConfigPtr->base->CRH &=~ (3u << ((ConfigPtr->GPIO_PinNumber - 8 ) * 4 + 2)); 		// Disable pull up, pull down
// ConfigPtr->base->CRH |=  (1U <<  ((ConfigPtr->GPIO_PinNumber - 8) * 4)); 			// Set pin as output

/* Check parameter */ 
	if (check_GPIO_parameter(ConfigPtr->GPIO_PinNumber))
	{
		return;
	}
	
	else
	{
		/*Enable Clock for PORT*/		
		RCC_PORT_APB2ENR |= (1<<ConfigPtr->GPIO_PORT);
		if (ConfigPtr->GPIO_PinMode == INPUT_MODE) //INPUT
		{
			if(ConfigPtr -> GPIO_PinNumber < 8)
			{
				/*Rest GPIO_PinNumber CNF*/
				ConfigPtr -> base -> CRL &=~ (3u << ((ConfigPtr->GPIO_PinNumber) *4 +2));
				
				ConfigPtr->base->CRL |= (ConfigPtr->GPIO_CNF << ((ConfigPtr->GPIO_PinNumber) * 4 +2)); // Set CNF mode
				if (ConfigPtr->GPIO_CNF == PULL_INPUT )
				{					
					ConfigPtr->base->ODR |= (ConfigPtr->Pull_config << ConfigPtr->GPIO_PinNumber); 	 // set pull up/down
				}
				ConfigPtr->base->CRL &=~ (3u << (ConfigPtr->GPIO_PinNumber) * 4 ); 					 // Set pin as input
			}	
			else
			{
				/*Rest GPIO_PinNumber CNF*/
				ConfigPtr -> base -> CRH &=~ (3u << ((ConfigPtr->GPIO_PinNumber - 8 ) *4 +2));

				ConfigPtr->base->CRH |=  (ConfigPtr->GPIO_CNF << (((ConfigPtr->GPIO_PinNumber) - 8)  * 4 +2)); 	 // Set CNF mode
				if (ConfigPtr->GPIO_CNF == PULL_INPUT )
				{					
					ConfigPtr->base->ODR |= (ConfigPtr->Pull_config << ConfigPtr->GPIO_PinNumber); 	 			// set pull up/down
				}
				ConfigPtr->base->CRH &=~ (3u << (ConfigPtr->GPIO_PinNumber - 8 ) * 4 ); 						 // Set pin as input
			}	

		}
			
		else // OUTPUT
		{
			if (ConfigPtr->GPIO_PinNumber < 8) 
			{
				ConfigPtr->base->CRL &=~ (3u << ((ConfigPtr->GPIO_PinNumber) * 4 + 2 )); 		/*Rest GPIO_PinNumber CNF*/
				ConfigPtr->base->CRL |=  (1U << (ConfigPtr->GPIO_PinNumber) * 4 );        		// Set pin as output
			}
			else
			{
				ConfigPtr->base->CRH &=~ (3u << ((ConfigPtr->GPIO_PinNumber - 8 ) * 4 + 2)); 		/*Rest GPIO_PinNumber CNF*/
				ConfigPtr->base->CRH |=  (1U <<  ((ConfigPtr->GPIO_PinNumber - 8) * 4)); 			// Set pin as output
			}
		}	
	}	
}

void GPIO_WriteToOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber, unsigned char value)
{
    /* Check parameter */
	if (check_GPIO_parameter(PinNumber))
	{
		return;
	}
	else
	{
		if(value == 0)
		{
			pGPIOx ->ODR &=~ (1u << PinNumber);
		}
		else if(value ==1)
		{
			pGPIOx ->ODR |= (1u << PinNumber);
		}
	}
}


void GPIO_SetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */
	if (check_GPIO_parameter(PinNumber))
	{
		return;
	}
	else
	{
		pGPIOx->ODR |= (1U << PinNumber);
	}
  
}

void GPIO_ResetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */
	if (check_GPIO_parameter(PinNumber))
	{
		return;
	}
	else
	{
		pGPIOx->ODR &=~ (1U << PinNumber);
	}
}

void GPIO_ToggleOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */
	if (check_GPIO_parameter(PinNumber))
	{
		return;
	}
	else
	{
    	pGPIOx->ODR ^= (1u << PinNumber);
	}
}


unsigned char GPIO_ReadFromInputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    /* Check parameter */
	if (check_GPIO_parameter(PinNumber))
	{
		return 0;
	}

	else
	{		
		unsigned char value;
		value = (unsigned char)((pGPIOx->IDR >> PinNumber)& 0x01);
		return value;	
	}
}
