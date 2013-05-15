
//#include <xpcc/architecture/platform.hpp>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
//#include "io/iodevice.hpp"
#include "device/uart0.hpp"

#include "device/timer2.hpp"
#include "device/gpio.hpp"
//#include "utils/iowrapper.hpp"
//#include "utils/wrapper.hpp"
//#include "uart_wrapper.hpp"



// Create a new UART object and configure it to a baudrate of 115200
/*
 void foo (output* pWhere){
	pWhere->write('a');
}
 */
GPIO g_led ('B',7);

int main()
{
	//char cmd[40];
	uint16_t test = 0;
	uint8_t read_d =0;

	g_led.SetOutput();

	Uart0 uart0(115200);
	sei();

	while (1)
	{
		//uart0 << (char *) "Hello World " <<  (char *) "TEST1  " <<  (char *) "TEST2  ";
		//_delay_ms(1000);
		//uart0 << _HEX(6543) << (char *) " ";
	//	_delay_ms(200);
	//	t_Timer2.get_timer(test);
	//	_delay_ms(200);
		//uart0 << (char *) "Timer: " << _HEX(test) <<  (char *) " " << _DEC(test) << (char *) " ";
		//uart0 << _BIN(test)  <<  (char *) " " << _OCT(test);
		_delay_ms(1000);
		uart0 >> read_d;
		_delay_ms(1000);
		uart0 << (char *) "RETURN:" << _DEC(read_d)  << read_d <<  (char *) " ";
	}

}
