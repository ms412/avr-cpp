/*
 * uart.cpp
 *
 *  Created on: 05.10.2012
 *      Author: Daniel
 */

#include "uart0.hpp"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../utils/wrapper.hpp"

//#if defined USART0_UDRE_vect

static CBuffer<uint8_t,20> TxBuffer;
static CBuffer<uint8_t,20> RxBuffer;

Uart0::Uart0(uint32_t baudrate) {
	SetBaudRate(baudrate);
	m_txByte = 0;
	m_rxByte = 0;
	m_error =0;
}
//virtual void Uart0::write(uint8_t c){PutChar(c);}
/*
void Uart0::write(const char *s){
	char c;
	while ((c = *s++)){
		Uart0::write(static_cast<uint8_t>(c));
	}

}
*/
void Uart0::PutChar(uint8_t c){

	if (!TxBuffer.isFull()){
		TxBuffer.Put(c);
		m_txByte++;
		//UDR0 = 0x99;
		//_delay_ms(200);
		//UDR0 = c;
		//UCSR0B |= (1 << UDRIE0);
		UART_CONTROL |= (1 << UDRIE);


	//	UART0_CONTROL |=(1<<UDRIE0);
	}else{
	//	return false;
	}
	//return true;
}

bool Uart0::read(uint8_t &c)
{
	if (RxBuffer.isEmpty()) {
		//UDR = 0x99;
		return false;
	}
	else {
		RxBuffer.Get(c);
	//	UDR = 0x98;
	}
	return true;
}
/*
bool Uart0::read(char *str, int size)
{
	char *cp;
	uint8_t c;
	size--;
	for (c = 0, cp = str; c != '\n' && size > 0; size--, cp++)
	{
		if (RxBuffer.Get(c)!=true)
		{
			return false;
		}else{
			*cp = (char)c;
		}
	}
	*cp = '\0';
	return true;
}

*/
bool Uart0::GetChar(uint8_t &c)
{
	if (RxBuffer.isEmpty()) {
		return false;
	}
	else {
		RxBuffer.Get(c);
//		m_txByte++;
		//RxBuffer.pop();

		return true;
	}
}

void Uart0::GetIntStat(uint16_t &c){
	c= m_txByte;
}

ISR(USART0_UDRE_vect)
{
	cli();
	uint8_t c;
	if (!TxBuffer.isEmpty()){
		TxBuffer.Get(c);
		UDR = c;
	}else{
		// transmission finished, disable UDRE interrupt
		//UCSR0B &= ~(1 << UDRIE0);
		UART_CONTROL &= ~(1 << UDRIE);
	}
	sei();
}

ISR(USART0_RX_vect)
{
	// read error flags
	//error |= UCSR0A & ((1 << FE0) | (1 << DOR0));
	cli();
	uint8_t data = UDR;
	//UDR = 0xAA;
	RxBuffer.Put(data);
	sei();
//	m_rxByte++;
	//UDR0 = 0x99;
}


