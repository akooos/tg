#ifndef UTILS_H
#define UTILS_H

#include "../include/defs.h"
namespace Tg{
#ifdef USING_UNICODE
typedef std::string UTF8Str;
typedef std::u16string UTF16Str;
typedef std::u32string UTF32Str; 
typedef std::wstring UTFWStr; 
#endif

namespace Utils{
	/*!
	 * Only works for latin alphanums. Use UTF functions instead.
	 */
	std::string stdWStrToStr(const std::wstring &wstr){
		std::wstring ws(L"wstring");
		std::string s;
		s.assign(ws.begin(), ws.end()); 
		return s;
	}
	/*!
	 * Only works for latin alphanums. Use UTF functions instead.
	 */
	std::wstring stdStrToWStr(const std::string &str){
	   std::string s("string");
	   std::wstring ws;
	   ws.assign(s.begin(), s.end());
	   return ws;
	}
#ifdef USING_UNICODE
#ifdef USING_BOOST
	Tg::UTF8Str stdStrToUtf8(const std::string &str,const std::string & encoding_from = "ISO-8859-2" ){
		return (std::string) boost::locale::conv::to_utf<char>(str,encoding_from);
	}
	Tg::UTFWStr stdWStrToUtf32(const std::string &str,const std::string & encoding_from = "ISO-8859-2" ){

		return boost::locale::conv::to_utf<wchar_t>(str,encoding_from);
	}
	Tg::UTF16Str stdStrToUtf16(const std::string &str,const std::string & encoding_from = "ISO-8859-2" ){

		return boost::locale::conv::to_utf<char16_t>(str,encoding_from);
	}
	Tg::UTF32Str stdStrToUtf32(const std::string &str,const std::string  encoding_from = "ISO-8859-2" ){
		return  boost::locale::conv::to_utf<char32_t>(str,encoding_from) ;
	}
	//------ UTF TO UTF ---------------------
	Tg::UTF16Str utf8ToUtf16(const std::string &str){
		return boost::locale::conv::utf_to_utf<char16_t> (str);
	}
	Tg::UTF32Str utf16ToUtf32(const std::string &str){
		return boost::locale::conv::utf_to_utf<char32_t> (str);
	}
	Tg::UTF32Str utf8ToUtf32(const std::string &str){
		return boost::locale::conv::utf_to_utf<char32_t> (str);
	}
/*!
 * \Deprecrated UCS-2 is a subset of UTF-16 
 */
	std::u16string utf8ToUcs2(const std::string &str){
		NOT_YET_IMPLEMENTED
		return std::u16string(u"asd");
	}
#else
	//FIXME add same functions as above 
	//for MSVC (GCC does not support these function(->codecvt)) so built with boost is not necessary
	//C++11 standard defines these only libstdc++ has not implemented yet.
	UTF16Str utf8ToUtf16(const std::string &str){
		std::wstring_convert<std::codecvt_utf8_utf16<char>,char16_t > converter;
		return converter.from_bytes(str);
	}
	UTF32Str utf16ToUtf32(const std::string &str){
		std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char32_t > converter;
		return converter.from_bytes(str);
	}


	UTF32Str utf8ToUtf32(const std::string &str){
		std::wstring_convert<std::codecvt_utf8<char32_t> > converter;
		return converter.from_bytes(str);
	}
/*!
 * \Deprecrated UCS-2 is a subset of UTF-16 
 */	
    UTF16Str utf8ToUcs2(const std::string &str){
		std::wstring_convert<std::codecvt_utf8<char16_t> > converter;
		return converter.from_bytes(str);
	}

#endif
#endif
}

}
#endif
