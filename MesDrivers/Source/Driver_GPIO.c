#include "stm32f10x.h"
#include "Driver_GPIO.h"


//RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
//RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN;

void MyGPIO_Init ( MyGPIO_Struct_TypeDef * GPIOStructPtr) {
	if (GPIOStructPtr->GPIO==GPIOA) RCC->APB2ENR |= RCC_APB2ENR_IOPAEN ;
	else if (GPIOStructPtr->GPIO==GPIOB) RCC->APB2ENR |= RCC_APB2ENR_IOPBEN ;
	else if (GPIOStructPtr->GPIO==GPIOC) RCC->APB2ENR |= RCC_APB2ENR_IOPCEN ;
	
	if (GPIOStructPtr->GPIO_Pin >= '0' && GPIOStructPtr->GPIO_Pin <= '7' ){
		
			
	}
	else
		
	
}

int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
	if (GPIO_Pin >= '0' && GPIO_Pin <= '7' )
			GPIO->CRL = 
	else
			
}