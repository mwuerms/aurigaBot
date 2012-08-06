/*
 * leds.c
 *
 *  Created on: 05.08.2012
 *      Author: martin
 */

#include "leds.h"

uint16_t led_state = 0;

void ledProc(void *pvParameters)
{
	// init
	led_state = 0;
	LEDsOff();
	LEDsOut();

	while (1) {
		// set led from state
		switch(led_state) {
		case 0:
			LED1Off();
			LED2Off();
			led_state++;
			break;

		case 1:
			LED1On();
			LED2Off();
			led_state++;
			break;

		case 2:
			LED1Off();
			LED2On();
			led_state++;
			break;

		case 3:
		default:
			LED1On();
			LED2On();
			led_state = 0;
			break;

		}

		// timeout
		vTaskDelay(500 / portTICK_RATE_MS);
	}
}
