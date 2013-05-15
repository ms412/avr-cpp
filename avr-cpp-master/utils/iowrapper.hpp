/*
 * iowrapper.hpp
 *
 *  Created on: 11.10.2012
 *      Author: Daniel
 */

#ifndef IOWRAPPER_HPP_
#define IOWRAPPER_HPP_

//#include "iodevice.hpp"

template<typename T>
class IOWrapper     //: public IODevice
{
	T &m_device;
public:
	IOWrapper( T&  device):  m_device(device){}

	virtual void write(uint8_t c){
		m_device.write(c);
	}

	virtual void write(const char *s){
		char c;
		while ((c = *s++)){
			m_device.write(static_cast<uint8_t>(c));
		}

	}

};



#endif /* IOWRAPPER_HPP_ */
