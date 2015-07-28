#ifndef VALUE_H
#define VALUE_H

#include "converters.h"

namespace Tg {

  template <class T>
  class Value : public ConverterString, ConverterNumber{

	 T data; 
     Value(){}

	 public:
	   Value (const T &data ):data(data){}
	   Value( const Value &other){			
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
