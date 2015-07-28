#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "converters.h"

namespace Tg{

   class Identifier : public ConverterString{

	   std::string data;

   public:
	     explicit Identifier(std::string &id):data(id){}


	std::string toStdString() const{ 
		return data; 
	}
	std::wstring toWideString() const{

		return std::wstring(L"");
	}
	std::string toUtf8() const{
		
		return std::string(u8"");
	}
	std::u16string toUtf16() const{
		
		return std::u16string(u"");
	}
	std::u32string toUtf32() const{
		
		return std::u32string(U"");
	}

   };
   
}

#endif
