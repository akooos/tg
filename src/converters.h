#ifndef CONVERTERS_H 
#define CONVERTERS_H

#include "utils.h"

/*! 
 *   \author Akos Toth 
 *   \email zuiadaton@gmail.com
 *
 */
struct ConverterString{

	virtual std::string toStdString() const{ 
		NOT_YET_IMPLEMENTED 
		return	std::string(""); 
	}
#ifdef USING_UNICODE
	virtual std::wstring toWideString() const{
		NOT_YET_IMPLEMENTED
		return std::wstring(L"");
	}
	virtual std::string toUtf8() const{
		NOT_YET_IMPLEMENTED
		return std::string(u8"");
	}
	virtual std::u16string toUtf16() const{
		NOT_YET_IMPLEMENTED
		return std::u16string(u"");
	}
	virtual std::u32string toUtf32() const{
		NOT_YET_IMPLEMENTED
		return std::u32string(U"");
	}
#endif
};
struct ConverterNumber
{
	virtual double toDouble() const{
		NOT_YET_IMPLEMENTED
		return 0.0;
	}
	virtual float toFloat() const{
		NOT_YET_IMPLEMENTED
		return 0.0f;
	}
	virtual int toInt() const{
		NOT_YET_IMPLEMENTED
		return 0;
	}
};

#endif
