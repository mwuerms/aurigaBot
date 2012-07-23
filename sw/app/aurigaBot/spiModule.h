/*
 * spiModule.h
 *
 *  Created on: 23.07.2012
 *      Author: martin
 */

#ifndef _SPIMODULE_H_
#define _SPIMODULE_H_

/* - Includes -------------------------------- */
/* Standard includes. */
#include <stdlib.h>
#include <signal.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/* - Defines -------------------------------- */
#define SPI_TARGET_GYRO		1
#define SPI_TARGET_ACCEL	2

#define SPI_MODULE_UCA0		1
#define SPI_MODULE_UCA1		2
#define SPI_MODULE_UCB0		3
#define SPI_MODULE_UCB1		4

#define SPI_SPEED_SMCLK		1

#define SPI_ROLE_MASTER		1

/* - Markos --------------------------------- */

/* - Typedefs ------------------------------- */
struct spi_module_init_t {
	uint8_t target;
	uint8_t module;
	uint8_t	speed;
	uint8_t role;
};

/* - Variables ------------------------------ */

/* - Functions ------------------------------ */
void vSpiModule(void *pvParameters);

#endif /* _SPIMODULE_H_ */


/* - Includes -------------------------------- */
/* Standard includes. * /
#include <stdlib.h>
#include <signal.h>

/ * Scheduler includes. * /
#include "FreeRTOS.h"
#include "task.h"
*/
/* - Defines -------------------------------- */

/* - Markos --------------------------------- */

/* - Typedefs ------------------------------- */

/* - Variables ------------------------------ */

/* - Functions ------------------------------ */
