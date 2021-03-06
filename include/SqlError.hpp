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

#ifndef BREWPIPP_SQL_ERROR_HPP
#define BREWPIPP_SQL_ERROR_HPP

#include "brewpipp_config.hpp"
#include <stdexcept>
#include <cassert>
#include <string>

# define sql_assert(expr, line, file)										\
((expr)															\
? __ASSERT_VOID_CAST (0)										\
: throw SqlError(__STRING(expr), line, file))

#ifdef BREWPIPP_ODBC
#include <sql.h>
#include <sqlext.h>


#define sql_succeed(expr, handle, type, line, file)						\
(SQL_SUCCEEDED(expr)										\
? __ASSERT_VOID_CAST (0)									\
: throw SqlError(__STRING(expr), handle, type, line, file))
#else

#endif
namespace brewpipp{
	
class SqlError : public std::runtime_error{
public:
	SqlError(const std::string &operation, SQLHANDLE handle, SQLSMALLINT type, const int &line, const std::string &file);
	SqlError(const std::string &what, const int &line, const std::string &file);
	
	virtual ~SqlError();
};
	
} //namespace brewpipp

#endif //ndef BREWPIPP_SQL_ERROR_HPP