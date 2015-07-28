#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "converters.h"
#ifdef USING_BOOST
#include <boost/locale.hpp>

#endif
namespace Tg{

   class Identifier : public ConverterString{

	   std::string data;

   public:
	     explicit Identifier(const std::string &id):data(id){}


	std::string toStdString() const{ 
		return data; 
	}
	std::wstring toWideString() const{

#ifdef USING_BOOST
       return boost::locale::conv::to_utf<wchar_t>(data,"ISO-8859-2");
#else 
#error "Ops no implementation other than boost..."

#endif
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
