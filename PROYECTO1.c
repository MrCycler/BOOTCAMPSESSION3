#include <stdint.h> //LIBRERIAS
#include "tm4c123gh6pm.h"//
//PROYECTO 1 : TRAFFIC LIGHT

void main(void) {
	uint32_t n; // VARIABLE 32 BITS
	//
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
	while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R4)==0) { }
	//RELOJ DEL PUERTO E
	
	GPIO_PORTE_DIR_R |= 0x0E; //ENTRADA O SALIDA?
	GPIO_PORTE_DR8R_R |=0x0E; //CORRIENTE?
	GPIO_PORTE_DEN_R |=0x0E; //SEÑAL DIGITAL?
	
	while(1){ //FOREVER RUN A TASK
		GPIO_PORTE_DEN_R &=~0x08;//RESET GREEN
		GPIO_PORTE_DEN_R |=0x02;//SET RED	
		for(n = 0; n < 800000; n++);//WAIT
		GPIO_PORTE_DEN_R &=~0x02;//RESET RED
		GPIO_PORTE_DEN_R |=0x04;//SET YELLOW
		for(n = 0; n < 800000; n++);//WAIT
		GPIO_PORTE_DEN_R &=~0x04;//RESET YELLOW
		GPIO_PORTE_DEN_R |=0x08;//SET GREEN
		for(n = 0; n < 800000; n++);//WAIT
		} 
	} 