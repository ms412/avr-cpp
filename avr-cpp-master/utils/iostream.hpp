/*
 * iostream.hpp
 *
 *  Created on: 13.10.2012
 *      Author: Daniel
 */

#ifndef IOSTREAM_HPP_
#define IOSTREAM_HPP_

class IOStream
{
public :

		IOStream(IODevice& device);

		inline IOStream&
		write(char c)
		{
			this->device->write(c);
			return *this;
		}

		IOStream&
		operator << (const unsigned char& v)
		{
			this->writeInteger(static_cast<uint16_t>(v));
			return *this;
		}

		IOStream&
		operator << (const char& v)
		{
			this->device->write(v);
			return *this;
		}

		IOStream&
		operator << (const uint16_t& v)
		{
			this->writeInteger(v);
			return *this;
		}




#endif /* IOSTREAM_HPP_ */
