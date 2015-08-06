#ifndef VALUE_H
#define VALUE_H

#include "converters.h"

namespace Tg {

  class Evaluable : public ConverterString, ConverterNumber{ };

  template <class T>
  class Value : public Evaluable {

	 T data; 
         Value(){}

	 public:
	   Value(const T &data ):data(data){}
           value( const Value &other){			
			data = other.data;
	   }	   
	   Value & operator =(const Value &other){
	   		if ( this != &other ){
				data = other.data;
			}
	   }
	   
	
  };
}

#endif
