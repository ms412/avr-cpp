/*
 * uart.hpp
 *
 *  Created on: 05.10.2012
 *      Author: Daniel
 */

#ifndef UART0_HPP_
#define UART0_HPP_


#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include "../utils/fifo.hpp"
#include "../utils/wrapper.hpp"
//class Wrapper;


#if defined (__AVR_AT90CAN128__)
 #define UART_STATUS   UCSR0A
 #define UART_CONTROL  UCSR0B
 #define UART_MODE     UCSR0C
// #define UART_DATA     UDR0
 #define UDRIE 		   UDRIE0
 #define UBRRL			UBRR0L
 #define UBRRH			UBRR0H
 #define MODE_SELECT	UMSEL0
 #define CHARSIZE		UCSZ0
#define RXEN			RXEN0
#define TXEN			TXEN0
#define RXCIE			RXCIE0
#define U2X				U2X0
#define UDR				UDR0


#else
 #error "no UART definition for MCU available"
#endif

#define UBRR_CALC(baudRate,xtalCpu) ((xtalCpu)/((baudRate)*8l)-1)

	#define HEX 16
	#define DEC 10
#define OCT 8
#define BIN 2

	#define _HEX(a)		_BASED(a, HEX)
	#define _DEC(a)		_BASED(a, DEC)
#define _OCT(a)		_BASED(a, OCT)
#define _BIN(a)		_BASED(a, BIN)



	struct _BASED
	{
		uint16_t val;
		int base;
		_BASED(uint16_t v, int b): val(v), base(b)
		{}
	};

class Uart0 {


public:
	// constructor
	Uart0(uint32_t baudrate);

	Uart0 & operator<<(char *s){
		for (uint8_t i = 0; i<strlen(s);i++){
			Uart0::write(s[i]);
		}
		return *this;
	}

	Uart0 & operator<<(uint8_t i){
		//for (uint8_t i = 0; i<strlen(s);i++){
			Uart0::write(i);

		return *this;
	}

	Uart0 & operator<<( const _BASED &arg){
		ultoa (arg.val,m_buffer,arg.base);
		for (uint8_t i = 0; i < strlen(m_buffer);i++){
			Uart0::write(m_buffer[i]);
		}
		return *this;
	}

	Uart0 & operator>>(uint8_t &c){
		bool ret;
		ret = read (c);
		//UDR = c;
	}

	void SetBaudRate(uint32_t baudrate = 9600){

	    UBRR0H = (unsigned char)(UBRR_CALC(baudrate,F_CPU) >> 8);
	    UBRR0L = (unsigned char) UBRR_CALC(baudrate,F_CPU);

	    UART_STATUS = (1<<U2X0);

	    /* Enable UART receiver and transmitter */
	    UART_CONTROL = ( ( 1 << RXEN0 ) | ( 1 << TXEN0 ) );

	    /* Set frame format: 8N1 */
	    UART_MODE = (3<<CHARSIZE);

	    /* Enable Interrupt */
	    UART_CONTROL |= (1<<TXEN0) | (1<<RXEN0) | (1 << RXCIE0);
	};

	void write(uint8_t c){PutChar(c);}
	//virtual void write(const char *s);
	bool read(uint8_t &c);
	//virtual bool read(char *str, int size);

	void PutChar(uint8_t);
	bool GetChar(uint8_t& c);
	void GetIntStat(uint16_t &c);

protected:

	//volatile bool m_readyToTx;

private:
	uint16_t m_txByte, m_rxByte, m_error;
	char m_buffer [sizeof(uint16_t)*8+1];

};


#endif /* UART0_HPP_ */
