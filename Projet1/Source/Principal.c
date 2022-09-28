#include "stm32f10x.h"
#include "Driver_GPIO.h"




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
