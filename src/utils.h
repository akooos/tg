#ifndef UTILS_H
#define UTILS_H

#include "../include/defs.h"
#include "pattern_match.h"


using  Tg::Exceptions::E_STREAM_READ_ERROR;

namespace Tg{
#ifdef USING_UNICODE
typedef std::string UTF8Str;
typedef std::u16string UTF16Str;
typedef std::u32string UTF32Str;
typedef std::wstring UTFWStr;
#endif


namespace {

  template <  class Container, class T = typename Container::value_type >
    std::ostream& printToStream (
      std::ostream& out,
      const Container & cntr )
    {
      if ( !cntr.empty() ) {

              std::copy (cntr.begin(),
                         cntr.end(),
                         std::ostream_iterator<T>(out, " "));

      }

            return out;
    }
    template <  class Container, class T = typename Container::value_type >
    void printCout(const Container & cntr){
       printToStream<Container,T>(std::cout,cntr);
       std::cout << std::endl;
    }
/*

  template <  class Container, class T = typename Container::value_type >
  std::ostream& operator<< (
                std::ostream& out,
                const Container & cntr )
  {
    if ( !cntr.empty() ) {
      out << '[';
      std::copy (cntr.begin(),
                       cntr.end(),
                       std::ostream_iterator<T>(out, ","));
          out << "\b\b]";
    }
      return out;
  }
*/   std::string getline2(
           std::istream &strm, 
           const std::vector<char> &delimiter = {'\n'} 
           )
   {
       std::string result;
       char *buffer = new char;
       size_t match_index = 0;

       while( !(strm.eof() || strm.fail()) ){

           strm.read(buffer,1);
           if ( *buffer == delimiter[match_index] ){
               if ( match_index == delimiter.size()-1 ){
                    delete buffer;
                    return result;
               }else{
                   ++match_index;
               }

           }else{
                match_index = 0;
                result.append(buffer,1);
           }


       }

       delete buffer;
       return result;


   }


   std::string getline(
           std::istream &strm, 
           const std::vector<char> &delimiter = {'\n'}, 
           const std::size_t max_buffer_size = 1024
           )
   {
       assert( max_buffer_size > 0 );
       std::string result;

       std::streampos pos = 0;
      
       typedef std::vector<char>::const_iterator _VecIterator;
       char *buffer = new char[max_buffer_size+1];
       
       while( !(strm.eof() || strm.fail()) ){

           pos = strm.tellg();
           strm.read(buffer,max_buffer_size);
           std::streamsize read_len = strm.gcount();
           buffer[ read_len ] = '\0';
           std::cout << "Buffer loaded =[" << buffer << "]"<< std::endl;
           std::cout << "Read size " << (int)read_len << " B" << std::endl;
           size_t i = 0,j = 0;
           while( buffer[i] != '\0' ){
               for(j = 0 ; j < delimiter.size(); ++j){
                   if ( buffer[i+j] != delimiter[j] )
                       break;
               }
               if ( j == delimiter.size() ){
                   result.append(buffer,i);  
                   if (strm.tellg()== -1 ){
                       strm.clear();
                   }

                   std::streamoff offset =  pos + static_cast<long int>(i+delimiter.size());
                   std::cout << "Seek pos by offset " << (int)  offset << std::endl;
                   std::cout << "From tellg=" << strm.tellg() << std::endl;
                   strm.seekg(offset,strm.beg) ;
                   std::cout << "Changed to tellg=" << strm.tellg() << std::endl;
                   delete[] buffer;
                   return result;
               }
               ++i;
           }

           result.append(buffer);
       }

       delete[] buffer;
       return result;


   }




    inline std::string  strToLower(std::string data)
    {
      std::transform(data.begin(), data.end(), data.begin(), ::tolower);
      return data;
    }
    inline bool areStrsEqual(const std::string &str1,
                                                const std::string &str2
                                              )
    {

      return strToLower(str1) == strToLower(str2);
    }
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
