#include "stm32f10x.h"
#include "Driver_GPIO.h"

/*
int main (void)
{
	//RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN;
	
	//PC10 : LED
	GPIOC->CRH &= ~(0xF << 8);
	GPIOC->CRH |= (2 << 8);
	
	//PC8 : BUTTON
	GPIOC->CRH &= ~(0xF);
	GPIOC->CRH |= 4;
	
	while(1){
		if (GPIOC->IDR & (1 << 8)) {
			GPIOC->ODR &= ~(1 << 10);
		}else {
			GPIOC->ODR |= (1 << 10);
		}
	}
}
*/

int main (void)
{	
	//gpioStruct_1 for the LED and gpioStruct_2 for the button
	MyGPIO_Struct_TypeDef gpioStruct_1, gpioStruct_2;
	
	//PC10 : LED
	gpioStruct_1.GPIO = GPIOC;
	gpioStruct_1.GPIO_Conf = Out_Ppull;
	gpioStruct_1.GPIO_Pin = 10;
	
	// clock enable for LED GPIO
	MyGPIO_Init(&gpioStruct_1);
	
	
	//PC8 : BUTTON	
	gpioStruct_2.GPIO = GPIOC;
	gpioStruct_2.GPIO_Conf = In_Floating;
	gpioStruct_2.GPIO_Pin = 8;
	
	// clock enable for BUTTON GPIO
	MyGPIO_Init(&gpioStruct_2);
	
	while (1){
		if (MyGPIO_Read ( gpioStruct_2.GPIO, gpioStruct_2.GPIO_Pin )) {
				MyGPIO_Set ( gpioStruct_1.GPIO , gpioStruct_1.GPIO_Pin );
		}else {
				MyGPIO_Reset ( gpioStruct_1.GPIO , gpioStruct_1.GPIO_Pin );
		}
	}
}
