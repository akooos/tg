#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "converters.h"



namespace Tg{

	class Identifier : public ConverterString{

		std::string data;

		public:

		Identifier(const std::string &id):data(id){}

		std::string toStdString() const{ 
			return data; 
		}

	};

}

#endif
