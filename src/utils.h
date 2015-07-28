#ifndef UTILS_H
#define UTILS_H

#include "../include/defs.h"
namespace Utils{
#ifndef USING_BOOST
	std::u16string utf8ToUtf16(const std::string &str){
		std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t > converter;
		return converter.from_bytes(str);
	}

	std::u32string utf8ToUtf32(const std::string &str){
		std::wstring_convert<std::codecvt_utf8<char32_t> > converter;
		return converter.from_bytes(str);
	}

	std::u16string utf8ToUcs2(const std::string &str){
		std::wstring_convert<std::codecvt_utf8<char16_t> > converter;
		return converter.from_bytes(str);
	}
#else
	std::u16string utf8ToUtf16(const std::string &str){
		return std::u16string(u"Halihóó");
	}

	std::u32string utf8ToUtf32(const std::string &str){
		return std::u32string(U"Halalal");
	}

	std::u16string utf8ToUcs2(const std::string &str){
		return std::u16string(u"asd");
	}
#endif
}


#endif
