/*
 * accel.c
 *
 *  Created on: 23.07.2012
 *      Author: martin
 *
 * uses: UCB1, ISR
 */
#include "appGlobal.h"

volatile uint8_t*	accel_data;	// data pointer
volatile uint8_t	accel_len;	// length counter

/**
 * initialize accel SPI module
 */
void accelInit(void)
{
	// init spi
	UCB1CTL1 = cACCEL_CTL1;
	UCB1BRW  = cACCEL_BAUDRATE;
	UCB1CTL0 = cACCEL_CTL0;
	UCB1IE	 = 0;

	// CS
	ADSPISel();
	ADCSOut();
	ADCSHigh();

	UCB1CTL1 &= ~UCSWRST;
}

/**
 * write to accelerometer
 */
void accelWrite(uint8_t *data, uint8_t len)
{
	// vars
	accel_data	= data;
	accel_len	= len;

	// if len < 2 answer with error in queue

	// clear IFG
	UCB1IFG  = 0;

	// assert cs
	ADCSLow();

	// start
	UCB1TXBUF = *accel_data;
	accel_data++;
	accel_len--;

	// en IE
	UCB1IE	 = UCTXIE;
}

/**
 * read from accelerometer
 */
void accelRead(uint8_t *data, uint8_t len)
{
}

/**
 * ISR to handle SPI communication with accelerometer using UCB1
 */
interrupt (USCI_B1_VECTOR) accelISR(void)
{
    /* Any normal C code */
}

/*
static void _initModule(struct spi_module_init_t* mod_set) {
	switch(mod_set->target) {
	case SPI_TARGET_ACCEL:
		mod_set->module = SPI_MODULE_UCB1;
		UCB1CTL1 = UCSWRST;
		// Pins
		ADSPISel();
		ADCSOut();

		// Module
		mod_set->status = (uint8_t*)UCB1STAT;
		mod_set->txbuf  = (uint8_t*)UCB1TXBUF;
		mod_set->rxbuf  = (uint8_t*)UCB1RXBUF;
		mod_set->csport = (uint8_t*)P4DIR;
		mod_set->cspin  = p4_ADCS;
		CSHigh();

		UCB1BRW = mod_set->baudrate;
		UCB1CTL0 = mod_set->ctl0;
		UCB1CTL1 = mod_set->ctl1;
		break;

	case SPI_TARGET_GYRO:
	default:
		mod_set->module = SPI_MODULE_UCB0;
		UCB0CTL1 = UCSWRST;
		// Pins
		GYSPISel();
		GYCSOut();

		// Module
		mod_set->status = (uint8_t*)UCB0STAT;
		mod_set->txbuf  = (uint8_t*)UCB0TXBUF;
		mod_set->rxbuf  = (uint8_t*)UCB0RXBUF;
		mod_set->csport = (uint8_t*)P2DIR;
		mod_set->cspin  = p2_GYCS;
		CSHigh();

		UCB0BRW = mod_set->baudrate;
		UCB0CTL0 = mod_set->ctl0;
		UCB0CTL1 = mod_set->ctl1;
	}
}
/*
/**
 * spi module
 * func for task
 * give pointer to init struct on task creation
 * @param	(struct spi_module_init_t*)
 * /
void vSpiModule(void *pvParameters)
{
	struct spi_module_init_t	module;
	struct spi_data_t*			data;

	// local copy
	module.target 	= ((struct spi_module_init_t*)(pvParameters))->target;
	module.module 	= ((struct spi_module_init_t*)(pvParameters))->module;
	module.ctl0 	= ((struct spi_module_init_t*)(pvParameters))->ctl0;
	module.ctl1		= ((struct spi_module_init_t*)(pvParameters))->ctl1;
	module.queue	= ((struct spi_module_init_t*)(pvParameters))->queue;

	// initialize SPI Module
	_initModule(&module);

	while(1) {
		// wait until there is something in the queue
		if(xQueueReceive((xQueueHandle) module.queue, (void*)(data), 10)) {
		if(data->ctrl & fSPI_DIR_WR)


		// give answer
		data->ctrl |= fSPI_DONE;

		}
	}
}
*/
