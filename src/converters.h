#ifndef CONVERTERS_H 
#define CONVERTERS_H

#include "../include/defs.h"
/*! 
 *   \author Akos Toth 
 *   \email zuiadaton@gmail.com
 *
 */
struct ConverterString{

	std::string toStdString() const{ 
		NOT_YET_IMPLEMENTED 
		return	std::string(""); 
	}
#ifdef USING_UNICODE
	std::wstring toWideString() const{
		NOT_YET_IMPLEMENTED
		return std::wstring(L"");
	}
	std::string toUtf8() const{
		NOT_YET_IMPLEMENTED
		return std::string(u8"");
	}
	std::u16string toUtf16() const{
		NOT_YET_IMPLEMENTED
		return std::u16string(u"");
	}
	std::u32string toUtf32() const{
		NOT_YET_IMPLEMENTED
		return std::u32string(U"");
	}
#endif
};
struct ConverterNumber
{
	double toDouble() const{
		NOT_YET_IMPLEMENTED
		return 0.0;
	}
	float toFloat() const{
		NOT_YET_IMPLEMENTED
		return 0.0f;
	}
	int toInt() const{
		NOT_YET_IMPLEMENTED
		return 0;
	}
};

#endif
