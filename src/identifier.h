#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "converters.h"
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
			return boost::locale::conv::to_utf<wchar_t>(data,"Latin1");
#else 

		std::wstring_convert<std::codecvt_utf8<wchar_t> > converter;
			return std::wstring(L"");
#endif
		}
		std::string toUtf8() const{

#ifdef USING_BOOST
			return boost::locale::conv::to_utf<char>(data,"Latin1");
#else 

		std::wstring_convert<std::codecvt_utf8<char> > converter;
			return std::string(u8"");
#endif	
		}
		std::u16string toUtf16() const{

#ifdef USING_BOOST
			return boost::locale::conv::to_utf<char16_t>(data,"Latin1");
#else 

		std::wstring_convert<std::codecvt_utf8<char16_t> > converter;
			return std::u16string(u"");
#endif		
		}
		std::u32string toUtf32() const{

#ifdef USING_BOOST
			return boost::locale::conv::to_utf<char32_t>(data,"Latin1");
#else 

		std::wstring_convert<std::codecvt_utf8<char32_t> > converter;
			return std::u32string(U"");
#endif			
		}

	};

}

#endif
