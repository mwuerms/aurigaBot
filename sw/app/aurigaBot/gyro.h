/*
 * gyro.h
 *
 *  Created on: 23.07.2012
 *      Author: martin
 */

#ifndef _GYRO_H_
#define _GYRO_H_

/* - Includes -------------------------------- */
#include "appGlobal.h"

/* - Defines -------------------------------- */
#define cGYRO_BAUDRATE		1
#define cGYRO_CTL0			(UCCKPH|UCCKPL|UCMSB|UCMST|UCMODE_0|UCSYNC)
#define cGYRO_CTL1			(UCSSEL_2|UCSWRST)

/* - Markos --------------------------------- */

/* - Typedefs ------------------------------- */

/* - Variables ------------------------------ */

/* - Functions ------------------------------ */
/**
 * initialize gyro SPI module
 */
void gyroInit(void);

/**
 * write to gyro
 * using ISR
 * data[0] = register
 * data[1,+] = write data from here
 * @param	pointer to data
 * @param	length of data
 * @param	pointer to queue handle for answer
 */
void gyroWrite(uint8_t *data, uint8_t len);

/**
 * read from gyro
 * using ISR
 * data[0] = register
 * data[1,+] = store read data into
 * @param	pointer to data
 * @param	length of data
 * @param	pointer to queue handle for answer
 */
void gyroRead(uint8_t *data, uint8_t len);

#endif /* _GYRO_H_ */
