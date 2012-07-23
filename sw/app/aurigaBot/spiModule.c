/*
 * spiModule.c
 *
 *  Created on: 23.07.2012
 *      Author: martin
 */

#include "appGlobal.h"

/**
 * initialize all modules depending on init struct
 * @param	pointer to init struct
 */
static void _initModule(struct spi_module_init_t* mod_set) {
	switch(mod_set->target) {
	case SPI_TARGET_ACCEL:
		// Pins
;
		// Module
		break;

	case SPI_TARGET_GYRO:
	default:
		mod_set->module = SPI_MODULE_UCB0;
		UCB0CTL1 = UCSWRST;
		// Pins
		P3SEL = 7;
		//GYSPISel();
		GYCSHigh();
		GYCSOut();

		// Module
		mod_set->status = (uint8_t*)UCB0STAT;
		UCB0BRW = mod_set->baudrate;
		UCB0CTL0 = mod_set->ctl0;
		UCB0CTL1 = mod_set->ctl1;
		break;
	}
}

/**
 * assert CS of module
 * = set cs low
 * @param	module number
 */
static void _assertCS(uint8_t target)
{
	if(target == SPI_TARGET_GYRO) {
		GYCSLow();
		return;
	}
	// if(target == SPI_TARGET_ACCEL)
//		ADCSLow();
}

/**
 * deassert CS of module
 * = set cs high
 * @param	module number
 */
static void _deassertCS(uint8_t target)
{
	if(target == SPI_TARGET_GYRO) {
		GYCSHigh();
		return;
	}
	// if(target == SPI_TARGET_ACCEL)
//		ADCSHigh();
}
/**
 * spi module
 * func for task
 * give pointer to init struct on task creation
 * @param	(struct spi_module_init_t*)
 */
void vSpiModule(void *pvParameters)
{
	struct spi_module_init_t module;

	// copy settings
	module.target 	= ((struct spi_module_init_t*)(pvParameters))->target;
	module.module 	= ((struct spi_module_init_t*)(pvParameters))->module;
	module.ctl0 	= ((struct spi_module_init_t*)(pvParameters))->ctl0;
	module.ctl1	= ((struct spi_module_init_t*)(pvParameters))->ctl1;

	// initialize SPI Module
	_initModule(&module);

	_assertCS(module.target);
	_deassertCS(module.target);
	while(1) {
		;
	}
}
