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

#define GYCSIn()	(P2DIR	&= ~p2_GYCS)
#define GYCSOut()	(P2DIR	|=  p2_GYCS)
#define GYCSLow()	(P2OUT	&= ~p2_GYCS)
#define GYCSHigh()	(P2OUT	|=  p2_GYCS)

/* - PORT3 ------------------ */
// UCB0
#define p3_GYMOSI	BIT0
#define p3_GYMISO	BIT1
#define p3_GYSCLK	BIT2
#define p3_3		BIT3
#define p3_4		BIT4

#define GYSPISel()	(P3SEL |= (p3_GYMOSI|p3_GYMISO|p3_GYSCLK))

/* - PORT1 ------------------ * /
#define p3	_BIT1
#define p3	_BIT2
#define p3	_BIT3
#define p3	_BIT4

/ * - PORT1 ------------------ * /
#define p3	_BIT1
#define p3	_BIT2
#define p3	_BIT3
#define p3	_BIT4
*/
#endif /* _IO_H_ */
