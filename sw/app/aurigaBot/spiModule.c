/*
 * spiModule.c
 *
 *  Created on: 23.07.2012
 *      Author: martin
 */

/* Standard includes. */
#include <stdlib.h>
#include <signal.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

#include "spiModule.h"
#include "io.h"

/**
 * initialize all modules depending on init struct
 * @param	pointer to init struct
 */
static void _initModule(struct spi_module_init_t* mod_init) {
	switch(mod_init->module) {
	case SPI_MODULE_UCA0:
		// Pins
		// Module
		break;

	case SPI_MODULE_UCA1:
		// Pins
		// Module
		break;

	case SPI_MODULE_UCB0:
		// Pins

		// Module
		break;

	case SPI_MODULE_UCB1:
	default:
			// Pins
			// Module
			break;
	}
}

/**
 * spi module
 * func for task
 * give pointer to init struct on task creation
 * @param	(struct spi_module_init_t*)
 */
void vSpiModule( void *pvParameters )
{
	struct spi_module_init_t mod_setting;
	mod_setting.target 	= ((struct spi_module_init_t*)(pvParameters))->target;
	mod_setting.module 	= ((struct spi_module_init_t*)(pvParameters))->module;
	mod_setting.speed 	= ((struct spi_module_init_t*)(pvParameters))->speed;
	mod_setting.role	= ((struct spi_module_init_t*)(pvParameters))->role;
	// initialize SPI Module
	_initModule(&mod_setting);

	while(1) {
		;
	}
}
