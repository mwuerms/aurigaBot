/*
 * io.h
 *
 *  Created on: 23.07.2012
 *      Author: martin
 *
 * define ALL IOs
 */

#ifndef _IO_H_
#define _IO_H_

#include "msp430f5342.h"

/* - direction - */
#define DIR_OUTPUT	1	// =1: output
#define DIR_INPUT	0	// =0: input

/* - PORT1 ------------------ */
#define p1_ADINT1	BIT0
#define p1_ADINT2	BIT1
#define p1_MOUT1_1	BIT2
#define p1_MOUT1_2	BIT3
#define p1_MOUT2_1	BIT4
#define p1_MOUT2_2	BIT5
#define p1_	GYINT1	BIT6
#define p1_	GYINT2	BIT7


/* - PORT2 ------------------ */
#define p2_GYCS		BIT7

#define GYCSIn()	(P2DIR &= ~p2_GYCS)
#define GYCSOut()	(P2DIR |=  p2_GYCS)
#define GYCSLow()	(P2OUT &= ~p2_GYCS)
#define GYCSHigh()	(P2OUT |=  p2_GYCS)

/* - PORT3 ------------------ */
// UCB0
#define p3_GYMOSI	BIT0
#define p3_GYMISO	BIT1
#define p3_GYSCLK	BIT2
#define p3_3		BIT3
#define p3_4		BIT4

#define GYSPISel()	(P3SEL |= (p3_GYMOSI|p3_GYMISO|p3_GYSCLK))

/* - PORT4 ------------------ */
#define p4_ADCS		BIT0
#define p4_ADMOSI	BIT1
#define p4_ADMISO	BIT2
#define p4_ADSCLK	BIT3
#define p4_TXD		BIT4
#define p4_RXD		BIT5
#define p4_6		BIT6
#define p4_IRREC	BIT7

#define ADCSOut()	(P4DIR |=  p4_ADCS)
#define ADSPISel()	(P4SEL |= (p4_ADMOSI|p4_ADMISO|p4_ADSCLK))
#define ADCSLow()	(P4OUT &= ~p4_ADCS)
#define ADCSHigh()	(P4OUT |=  p4_ADCS)

/* - PORT1 ------------------ */
#define p5_LED2		BIT1
#define p5_LED1		BIT7

#define LEDsOut	()	P5DIR |=  (p5_LED1|p5_LED2)
#define LEDsIn()	P5DIR &= ~(p5_LED1|p5_LED2)
#define LEDsOff()	P5OUT |=  (p5_LED1|p5_LED2)
#define LEDsOn()	P5OUT &= ~(p5_LED1|p5_LED2)

#define LED1Off()	P5OUT |=  (p5_LED1)
#define LED1On()	P5OUT &= ~(p5_LED1)

#define LED2Off()	P5OUT |=  (p5_LED2)
#define LED2On()	P5OUT &= ~(p5_LED2)

#endif /* _IO_H_ */
