/*
 * Distrubuted under The MIT License (MIT)
 *
 * Copyright (c) 2016 Aaron Bishop
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef BREWPIPP_UTIL_TTY_HPP
#define BREWPIPP_UTIL_TTY_HPP

#include "string.hpp"
#include <vector>
#include <sstream>
#include <boost/asio/serial_port.hpp>

namespace brewpipp {
	namespace util {
		class tty {
		public:
			static std::vector<string> list_serial_ports();
			
			tty(const string& port);
			~tty();
			
			size_t send() throw (boost::system::system_error);
			size_t receive() throw (boost::system::system_error);
			
			std::ostringstream out;
			std::istringstream in;
		private:
			boost::asio::serial_port m_serial;
		};
	}
}

#endif //BREWPIPP_UTIL_TTY_HPP