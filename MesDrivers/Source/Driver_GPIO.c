#include <stdio.h>
#include "stm32f10x.h"
#include "Driver_GPIO.h"

void MyGPIO_Init ( MyGPIO_Struct_TypeDef * GPIOStructPtr) {
	if (GPIOStructPtr->GPIO==GPIOA) {
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN ;
	}
	else if (GPIOStructPtr->GPIO==GPIOB) {
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN ;
	}
	else if (GPIOStructPtr->GPIO==GPIOC) {
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN ;
	}
	
	if ((int)GPIOStructPtr->GPIO_Pin >= 0 && (int)GPIOStructPtr->GPIO_Pin <= 7 ){
		GPIOStructPtr->GPIO->CRL &= ~(0xF << 4*(int)GPIOStructPtr->GPIO_Pin);
		GPIOStructPtr->GPIO->CRL |= GPIOStructPtr->GPIO_Conf << 4*(int)GPIOStructPtr->GPIO_Pin;
	}
	
	if ((int)GPIOStructPtr->GPIO_Pin >= 8 && (int)GPIOStructPtr->GPIO_Pin <= 15 ){
		GPIOStructPtr->GPIO->CRH &= ~(0xF << 4*((int)GPIOStructPtr->GPIO_Pin -8));
		GPIOStructPtr->GPIO->CRH |= GPIOStructPtr->GPIO_Conf << 4*((int)GPIOStructPtr->GPIO_Pin -8);
	}

}


int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
	if (GPIO->IDR & (1 << GPIO_Pin)) {
		return 1;
	} else {
		return 0;
	}
}

void MyGPIO_Set ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
	GPIO->ODR &= ~(1 << GPIO_Pin);
}

void MyGPIO_Reset ( GPIO_TypeDef * GPIO , char GPIO_Pin ) {
	GPIO->ODR |= (1 << GPIO_Pin);
}


