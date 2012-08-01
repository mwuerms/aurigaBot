/*
 * accel.h
 *
 *  Created on: 23.07.2012
 *      Author: martin
 */

#ifndef _ACCEL_H_
#define _ACCEL_H_

/* - Includes -------------------------------- */
#include "appGlobal.h"

/* - Defines -------------------------------- */
#define cACCEL_BAUDRATE		1
#define cACCEL_CTL0			(UCCKPH|UCCKPL|UCMSB|UCMST|UCMODE_0|UCSYNC)
#define cACCEL_CTL1			(UCSSEL_2|UCSWRST)

/*
#define SPI_TARGET_GYRO		1
#define SPI_TARGET_ACCEL	2

#define SPI_MODULE_UCA0		1
#define SPI_MODULE_UCA1		2
#define SPI_MODULE_UCB0		3
#define SPI_MODULE_UCB1		4
*/
/* - Markos --------------------------------- */

/* - Typedefs ------------------------------- */
/*
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
*/
/* - Variables ------------------------------ */

/* - Functions ------------------------------ */
/**
 * initialize accel SPI module
 */
void accelInit(void);

/**
 * write to accelerometer
 * using ISR
 * data[0] = register
 * data[1,+] = write data from here
 * @param	pointer to data
 * @param	length of data
 * @param	pointer to queue handle for answer
 */
void accelWrite(uint8_t *data, uint8_t len);

/**
 * read from accelerometer
 * using ISR
 * data[0] = register
 * data[1,+] = store read data into
 * @param	pointer to data
 * @param	length of data
 * @param	pointer to queue handle for answer
 */
void accelRead(uint8_t *data, uint8_t len);

#endif /* _ACCEL_H_ */
