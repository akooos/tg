#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "converters.h"

namespace Tg{
/*!
 * An Identifier always should be in ansi encoding
 */
	class Identifier : public ConverterString{

         std::string data;

      public:

        
        Identifier(const char *str):data(std::string(str)){}
		Identifier(const std::string &id = ""):data(id){}

		std::string toStdString() const{ 
			return data; 
		}
		Identifier operator=(const std::string &str){
		    this->data = str;
		    return *this;
		}
		Identifier operator=(const char *str){
          
          this->data = std::string(str);
          return *this;
        }
		bool operator==( const Identifier &rhs) const {
          
          return Tg::areStrsEqual(this->data,rhs.data);
        }
        bool operator<(const Identifier &rhs)const{
          return this->data < rhs.data;
        }

	};
   typedef std::set<Identifier> IdentifierSet;

}
#endif
