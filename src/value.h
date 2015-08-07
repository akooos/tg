#ifndef VALUE_H
#define VALUE_H

#include "converters.h"

namespace Tg {

  class Evaluable : public ConverterString, ConverterNumber{ };

  template <class T>
  class Value : public Evaluable {

	 T data; 
         Value():Evaluable(){}

	 public:
	   Value(const T &data ):Evaluable(),data(data){}
           Value( const Value &other){			
			data = other.data;
	   }	   
	   Value & operator =(const Value &other){
	   		if ( this != &other ){
				data = other.data;
			}
	   }
  };

  template<>
  class Value<std::string> : public Evaluable{

      std::string data; 
      Value(){}

	 public:
	   Value(const std::string &data ):Evaluable(),data(data){}
       Value( const Value &other){			
			data = other.data;
	   }	   
	   Value & operator =(const Value &other){
	   		if ( this != &other ){
				data = other.data;
			}
            return *this;
	   }
	  
  };

}

#endif
