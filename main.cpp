/*
 * main.cpp
 */
#include "matrix.h"
//#include "math.h"
#include <stdlib.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

MAX7219 m(SYSCTL_PERIPH_GPIOF,GPIO_PORTF_BASE,GPIO_PIN_2,GPIO_PIN_1,GPIO_PIN_3);


void noise(){
			m.write2Byte(digit0,rand()%256,rand()%256);
			m.write2Byte(digit1,rand()%256,rand()%256);
			m.write2Byte(digit2,rand()%256,rand()%256);
			m.write2Byte(digit3,rand()%256,rand()%256);
			m.write2Byte(digit4,rand()%256,rand()%256);
			m.write2Byte(digit5,rand()%256,rand()%256);
			m.write2Byte(digit6,rand()%256,rand()%256);
			m.write2Byte(digit7,rand()%256,rand()%256);
			SysCtlDelay(500000);
}


int main(void) {
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);




	
	while(true){
		noise();
	};
}
