/*
 * timer2.cpp
 *
 *  Created on: 10.10.2012
 *      Author: Daniel
 */
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer2.hpp"

//Timer2 Timer2;   // the CTimer0 instance

//-------------------------------------------------------------------
// The constructor provides all the required initialisation for
// this device.
//

CTimer2 t_Timer2;

CTimer2::CTimer2(void){
	//_delay_ms(1000);
	m_time = 0;

	cli();

	TIMSK2 |= (0<< TOIE2);
	ASSR   = (1<< AS2);

	TCNT2 = 0;              // clear TCNT2A
	TCCR2A |= (1<<CS22) | (1<<CS20);  // select precaler: 32.768 kHz / 128 = 1 sec between each overflow


	while((ASSR & 0x01) | (ASSR & 0x04));       // wait for TCN2UB and TCR2UB to be cleared

	TIFR2 = 0xFF;           // clear interrupt-flags

	TIMSK2 |= (1<< TOIE2);
	};

void CTimer2::get_timer(uint16_t &time){
	//uint32_t temp;
	//temp = time;
	time = m_time;
//	return m_time;
}

void TIMER2_OVF_vect() {

	//OCR2A=128;
	t_Timer2.m_time++;
	PORTB ^=(1<<PB7);
}


