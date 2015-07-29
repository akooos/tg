#ifndef UTILS_H
#define UTILS_H

#include "../include/defs.h"
namespace Utils{
	std::string stdWStrToStr(const std::wstring &wstr){
		std::wstring ws(L"wstring");
		std::string s;
		s.assign(ws.begin(), ws.end()); 
		return s;
	}
	std::wstring stdStrToWStr(const std::string &str){
	   std::string s("string");
	   std::wstring ws;
	   ws.assign(s.begin(), s.end());
	   return ws;
	}

#ifdef USING_BOOST
    std::string stdStrToUtf8(const std::string &str){
		return 
	}

	std::u16string utf8ToUtf16(const std::string &str){
		return  
	}

	std::u32string utf8ToUtf32(const std::string &str){
		return std::u32string(U"Halalal");
	}
/*!
 * \Deprecrated UCS-2 is a subset of UTF-16 
 */
	std::u16string utf8ToUcs2(const std::string &str){
		NOT_YET_IMPLEMENTED
		return std::u16string(u"asd");
	}
#else
	std::u16string utf8ToUtf16(const std::string &str){
		std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t > converter;
		return converter.from_bytes(str);
	}

	std::u32string utf8ToUtf32(const std::string &str){
		std::wstring_convert<std::codecvt_utf8<char32_t> > converter;
		return converter.from_bytes(str);
	}
/*!
 * \Deprecrated UCS-2 is a subset of UTF-16 
 */	
	std::u16string utf8ToUcs2(const std::string &str){
		std::wstring_convert<std::codecvt_utf8<char16_t> > converter;
		return converter.from_bytes(str);
	}

#endif
}


#endif
