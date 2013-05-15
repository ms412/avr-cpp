/*
 * wrapper.hpp
 *
 *  Created on: 13.10.2012
 *      Author: Daniel
 */

#ifndef WRAPPER_HPP_
#define WRAPPER_HPP_
#include "../device/uart0.hpp"
//#include "../device/uart1.hpp"
//#include "iodevice.hpp"
//class Uart1;
//class Uart2;
/*
template <class T>
inline Print &operator << (Print &stream, T arg) {stream.print(arg); return stream;}
class Wrapper     //: public IODevice
{
public:
	virtual void write(uint8_t c);
	virtual void write(const char *s);
	virtual bool read(uint8_t &c);
	virtual bool read(char *str, int size);

	inline
};
*/

class stream {

public:
	stream operator<<(stream c);
};



#endif /* WRAPPER_HPP_ */
