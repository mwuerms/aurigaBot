/*
 * spiModule.h
 *
 *  Created on: 23.07.2012
 *      Author: martin
 */

#ifndef _SPIMODULE_H_
#define _SPIMODULE_H_

/* - Includes -------------------------------- */
#include "appGlobal.h"

/* - Defines -------------------------------- */
#define SPI_TARGET_GYRO		1
#define SPI_TARGET_ACCEL	2

#define SPI_MODULE_UCA0		1
#define SPI_MODULE_UCA1		2
#define SPI_MODULE_UCB0		3
#define SPI_MODULE_UCB1		4

/* - Markos --------------------------------- */

/* - Typedefs ------------------------------- */
// init spi module
struct spi_module_init_t {
	void*		queue;
	uint8_t*	status;
	uint8_t*	txbuf;
	uint8_t*	rxbuf;
	uint8_t*	csport;
	uint16_t	baudrate;
	uint8_t		cspin;
	uint8_t 	target;
	uint8_t 	module;
	uint8_t 	ctl0;
	uint8_t 	ctl1;
};

// spi data
struct spi_data_t {
	uint16_t	ctrl;
	uint8_t		length;
	uint8_t* 	data;
};
#define fSPI_DIR_WR		BIT0	// =0: read, =1: write
#define fSPI_DONE		BIT8
#define fSPI_ERROR		BIT9

/* - Variables ------------------------------ */

/* - Functions ------------------------------ */
void vSpiModule(void *pvParameters);

#endif /* _SPIMODULE_H_ */
