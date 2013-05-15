/*
 * timer2.hpp
 *
 *  Created on: 10.10.2012
 *      Author: Daniel
 */

#ifndef TIMER2_HPP_
#define TIMER2_HPP_

extern "C" void TIMER2_OVF_vect(void) __attribute__ ((signal));

extern class CTimer2 t_Timer2;

class CTimer2 {
public:
	CTimer2(void);
	void get_timer(uint16_t &time);
private:

	friend void TIMER2_OVF_vect();
	uint16_t m_time;
};




#endif /* TIMER2_HPP_ */
