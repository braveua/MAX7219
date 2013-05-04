/*
 * matrix.cpp
 *
 *  Created on: 04.05.2013
 *      Author: braveua
 */

#include "matrix.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

MAX7219::MAX7219(unsigned long portSysctlPeriph, unsigned long portBase, unsigned char CLK, unsigned char DIN, unsigned char CS) {
	this->portSysctlPeriph = portSysctlPeriph;
	this->portBase = portBase;
	this->CLK = CLK;
	this->DIN = DIN;
	this->CS  = CS;

	SysCtlPeripheralEnable(portSysctlPeriph);
	GPIOPinTypeGPIOOutput(portBase, CS|CLK|DIN);
	GPIOPinWrite(portBase, 0xFF,0);

	writeByte(shutdown,0x01);
	writeByte(test,0x00);
	writeByte(scanlimit,0x07);
	writeByte(intensity,2);
	writeByte(decode,0x00);
}

void MAX7219::writeBit(char c){
	GPIOPinWrite(portBase, CLK|DIN, 0	 |(DIN*c));
	GPIOPinWrite(portBase, CLK|DIN, CLK|(DIN*c));
}

void MAX7219::writeByte(unsigned char addr, unsigned char data){
	int i;
	GPIOPinWrite(portBase, CS|DIN|CLK, 0);
	for(i=7;i>=0;i--){
		writeBit((addr&(1<<i))>>i);
	}
	for(i=7;i>=0;i--){
		writeBit((data&(1<<i))>>i);
	}
	GPIOPinWrite(portBase, CS|DIN|CLK, CS);
}

void MAX7219::write2Byte(unsigned char addr, unsigned char data, unsigned char data2){
	int i;
	GPIOPinWrite(portBase, CS|DIN|CLK, 0);
	for(i=7;i>=0;i--){
		writeBit((addr&(1<<i))>>i);
	}
	for(i=7;i>=0;i--){
		writeBit((data&(1<<i))>>i);
	}
	for(i=7;i>=0;i--){
		writeBit((addr&(1<<i))>>i);
	}
	for(i=7;i>=0;i--){
		writeBit((data2&(1<<i))>>i);
	}
	GPIOPinWrite(portBase, CS|DIN|CLK, CS);
}



