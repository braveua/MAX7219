/*
 * matrix.h
 *
 *  Created on: 04.05.2013
 *      Author: braveua
 */
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"



#ifndef MATRIX_H_
#define MATRIX_H_

//#define DIN GPIO_PIN_1 // Serial Data Input			  	/Serial input
//#define CLK GPIO_PIN_2 // Clock Input					 	/SHIFT CLOCK
//#define CS  GPIO_PIN_3 // Storage Register Clock Input	/LATCH
//#define PORT GPIO_PORTF_BASE

#define nop    0x00
#define digit0 0x01
#define digit1 0x02
#define digit2 0x03
#define digit3 0x04
#define digit4 0x05
#define digit5 0x06
#define digit6 0x07
#define digit7 0x08
#define decode 0x09
#define intensity 0x0A
#define scanlimit 0x0B
#define shutdown  0x0C
#define test 0x0F

class MAX7219 {
public:
	MAX7219(unsigned long portSysctlPeriph, unsigned long portBase, unsigned char CLK, unsigned char DIN, unsigned char CS);
	void writeByte(unsigned char addr, unsigned char data);
	void write2Byte(unsigned char addr, unsigned char data, unsigned char data2);
private:
	unsigned long portSysctlPeriph;
	unsigned long portBase;
	unsigned char CLK;
	unsigned char DIN;
	unsigned char CS;
	void writeBit(char c);
};

#endif /* MATRIX_H_ */
