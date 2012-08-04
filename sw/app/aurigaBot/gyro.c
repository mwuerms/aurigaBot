/*
 * gyro.c
 *
 *  Created on: 23.07.2012
 *      Author: martin
 *
 * uses: UCB0, ISR
 */
#include "appGlobal.h"

volatile uint8_t*	accel_data;	// data pointer
volatile uint8_t	accel_len;	// length counter

/**
 * initialize gyro SPI module
 */
void gyroInit(void)
{
	// init spi
	UCB0CTL1 = cACCEL_CTL1;
	UCB0BRW  = cACCEL_BAUDRATE;
	UCB0CTL0 = cACCEL_CTL0;
	UCB0IE   = 0;

	// CS
	GYSPISel();
	GYCSOut();
	GYCSHigh();


	UCB0CTL1 &= ~UCSWRST;
}

/**
 * write to gyro
 */
void gyroWrite(uint8_t *data, uint8_t len)
{
	// vars
	accel_data	= data;
	accel_len	= len;

	// if len < 2 answer with error in queue

	// clear IFG
	UCB0IFG = 0;

	// assert cs
	GYCSLow();

	// start
	UCB0TXBUF = *accel_data;
	accel_data++;
	accel_len--;

	// en IE
	UCB0IE  = UCTXIE;
}

/**
 * read from gyro
 */
void gyroRead(uint8_t *data, uint8_t len)
{
}

/**
 * ISR to handle SPI communication with gyro using UCB0
 */
interrupt (USCI_B0_VECTOR) gyroISR(void)
{
    /* Any normal C code */
}
