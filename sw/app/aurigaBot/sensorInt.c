/*
 * sensorInt.c
 *
 *  Created on: 04.08.2012
 *      Author: martin
 *
 * uses: P1IE, P1IFG
 */

#include "appGlobal.h"
#include "accel.h"
#include "gyro.h"
#include "io.h"

/**
 * ISR to handle interrupts from sensors (accel, gyro)
 */
interrupt (PORT1_VECTOR) gyroISR(void)
{
    if(P1IE & p1_ADINT1) {
    	if(P1IFG & p1_ADINT1) {
    		// Interrupt from accel, read out accel
    	}
    }

    if(P1IE & p1_GYINT1) {
		if(P1IFG & p1_GYINT1) {
			// Interrupt from gyro, read out gyro
		}
	}
}


