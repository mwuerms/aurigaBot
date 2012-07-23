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
struct spi_module_init_t {
	uint16_t	baudrate;
	uint8_t*	status;
	uint8_t 	target;
	uint8_t 	module;
	uint8_t 	ctl0;
	uint8_t 	ctl1;
};

/* - Variables ------------------------------ */

/* - Functions ------------------------------ */
void vSpiModule(void *pvParameters);

#endif /* _SPIMODULE_H_ */
